#include "global.h"
std::map<SteamAPICall_t, std::pair<void*, size_t>> reader;
S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileDelete(intptr_t instancePtr,const char* pchFile){
	zip_int64_t id=zip_name_locate(zip, pchFile, ZIP_FL_NOCASE);
	if (id == -1)return false;
	zip_delete(zip, id);
	zip_close(zip);
	zip = zip_open("E:\\data.zip", ZIP_CREATE, NULL);
	return true;
}
S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileExists(intptr_t instancePtr,const char* pchFile){
	zip_int64_t id = zip_name_locate(zip, pchFile, ZIP_FL_NOCASE);
	return (id != -1);
}
S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileForget(intptr_t instancePtr,const char* pchFile) {
	zip_int64_t id = zip_name_locate(zip, pchFile, ZIP_FL_NOCASE);
	if (id == -1)return false;
	if (-1 == zip_file_set_comment(zip, id, "forgotten", 10, ZIP_FL_ENC_CP437))return false;
	zip_close(zip);
	zip = zip_open("E:\\data.zip", ZIP_CREATE, NULL);
	return true;
}
S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FilePersisted(intptr_t instancePtr,const char* pchFile){
	zip_int64_t id = zip_name_locate(zip, pchFile, ZIP_FL_NOCASE);
	if (id == -1)return false;
	const char* comment;
	if(NULL==(comment=zip_file_get_comment(zip,id,NULL, ZIP_FL_ENC_STRICT)))
		return true;
	if (strcmp("forgotten", comment)!=0)return true;
	return false;
}
S_API int32 S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileRead(intptr_t instancePtr,const char* pchFile, void* pvData, int32 cubDataToRead){
	if (cubDataToRead == 0)return 0;
	zip_file_t* f = zip_fopen(zip, pchFile, ZIP_FL_NOCASE);
	if (f == NULL)return 0;
	zip_int64_t l = zip_fread(f, pvData, cubDataToRead);
	if (l == -1)l = 0;
	zip_fclose(f);
	return static_cast<int32>(l);
}
S_API SteamAPICall_t S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileReadAsync(intptr_t instancePtr,const char* pchFile, uint32 nOffset, uint32 cubToRead){
	size_t cub = static_cast<size_t>(cubToRead);

	zip_file_t* f = zip_fopen(zip, pchFile, ZIP_FL_NOCASE);
	if (f == NULL) return k_uAPICallInvalid;
	if (-1 == zip_fseek(f, nOffset, SEEK_SET)) {
		return k_uAPICallInvalid;
	}
	void* buffer;
	try {
		buffer = malloc(cubToRead);
	}catch (...) {
		zip_fclose(f);
		return k_uAPICallInvalid;
	}
	if (buffer == nullptr) {
		zip_fclose(f);
		return k_uAPICallInvalid;
	}
	zip_int64_t rsize=zip_fread(f, buffer, cubToRead);
	if (rsize != cubToRead) {
		free(buffer);
		zip_fclose(f);
		return k_uAPICallInvalid;
	}
	zip_fclose(f);
 	RemoteStorageFileReadAsyncComplete_t* data = reinterpret_cast<RemoteStorageFileReadAsyncComplete_t*>(malloc(sizeof(RemoteStorageFileReadAsyncComplete_t)));
	if (data == nullptr) {
		free(buffer);
		return k_uAPICallInvalid;
	}
	data->m_nOffset = nOffset;
	data->m_cubRead = cubToRead;

	data->m_eResult = k_EResultOK;
	data->m_hFileReadAsync = 0;
	SteamAPICall_t id = queue.insert(true, data);
	data->m_hFileReadAsync = id;
	reader[id] = std::pair<void*,size_t>(buffer,cubToRead);


	return id;
}
S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete(intptr_t instancePtr, SteamAPICall_t hReadCall, void* pvBuffer, uint32 cubToRead){
	if (reader.find(hReadCall) == reader.cend()) {
		return false;
	}
	if (cubToRead != reader[hReadCall].second) {
		return false;
	}
	void* buffer = reader[hReadCall].first;
	try {
		memcpy(pvBuffer, buffer, reader[hReadCall].second);
		free(buffer);
	}
 	catch (...) { 
		return false; 
	}
	FILE* fw = fopen("E:\\temp.bin", "wb");
	fwrite(pvBuffer, 1, cubToRead, fw);
	fclose(fw);
 	return true;
}
//S_API SteamAPICall_t S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileShare(const char* pchFile){}
S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileWrite(intptr_t instancePtr, const char* pchFile, const void* pvData, int32 cubData){
	FILE* fw = fopen("E:\\write.bin", "wb");
	fwrite(pvData, 1, cubData, fw);
	fclose(fw);


	bool Success = false;
	zip_source_t* s = zip_source_buffer(zip, pvData, cubData, 0);
	if (s == NULL) { 
		return false; 
	}
	try {
		zip_uint64_t t;
		if (-1 == (t = zip_file_add(zip, pchFile, s, ZIP_FL_OVERWRITE))) {
			zip_source_free(s);
		}
		else {
			Success = (0== zip_set_file_compression(zip, t, ZIP_CM_STORE, 0));
		}
	}
 	catch (...) {}
	zip_close(zip);
	zip = zip_open("E:\\data.zip", ZIP_CREATE, NULL);
	return Success;
}
S_API SteamAPICall_t S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileWriteAsync(intptr_t instancePtr, const char* pchFile, const void* pvData, uint32 cubData){
	if (!SteamAPI_ISteamRemoteStorage_FileWrite(instancePtr,pchFile, pvData, cubData))return k_uAPICallInvalid;
	RemoteStorageFileWriteAsyncComplete_t* data = reinterpret_cast<RemoteStorageFileWriteAsyncComplete_t*>(malloc(sizeof(RemoteStorageFileWriteAsyncComplete_t)));
	if(data!=nullptr)data->m_eResult = k_EResultOK;
	return queue.insert(false, data);
}
//S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel(UGCFileWriteStreamHandle_t writeHandle){}
//S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileWriteStreamClose(UGCFileWriteStreamHandle_t writeHandle){}
S_API UGCFileWriteStreamHandle_t S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen(const char* pchFile){
	MessageBoxA(0, "stream", "stream", MB_OK);
	return 0;
}
//S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t writeHandle, const void* pvData, int32 cubData){}
S_API int32 S_CALLTYPE SteamAPI_ISteamRemoteStorage_GetCachedUGCCount(intptr_t instancePtr){
	MessageBoxA(0, "UGC", "UGC", MB_OK);
	return 0;
}
S_API UGCHandle_t S_CALLTYPE SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle(intptr_t instancePtr, int32 iCachedContent) {
	return 0;
}
S_API int32 S_CALLTYPE SteamAPI_ISteamRemoteStorage_GetFileCount(intptr_t instancePtr){
	return static_cast<int32>(zip_get_num_entries(zip, 0));
}
S_API const char* S_CALLTYPE SteamAPI_ISteamRemoteStorage_GetFileNameAndSize(intptr_t instancePtr, int iFile, int32* pnFileSizeInBytes){
	zip_stat_t stat;
	zip_stat_init(&stat);
	if (!zip_stat_index(zip, iFile, 0, &stat)) {
		*pnFileSizeInBytes = 0;
		return "";
	}
 	if (stat.valid & ZIP_STAT_SIZE)
		* pnFileSizeInBytes = static_cast<int32>(stat.size);
	else
		*pnFileSizeInBytes = 0;

	if (stat.valid & ZIP_STAT_NAME)
		return stat.name;
	else
		return "";
}
S_API int32 S_CALLTYPE SteamAPI_ISteamRemoteStorage_GetFileSize(intptr_t instancePtr, const char* pchFile){
	zip_stat_t stat;
	zip_stat_init(&stat);
	if (0!=zip_stat(zip, pchFile, ZIP_FL_NOCASE, &stat)) {
		return 0;
	}
	if (stat.valid & ZIP_STAT_SIZE) {
		return static_cast<int32>(stat.size);
	}
	else {
		return 0;
	}
}

S_API int64 S_CALLTYPE SteamAPI_ISteamRemoteStorage_GetFileTimestamp(intptr_t instancePtr, const char* pchFile){
	zip_stat_t stat;
	zip_stat_init(&stat);
	if(!zip_stat(zip, pchFile, ZIP_FL_NOCASE, &stat))return 0;
	if (stat.valid & ZIP_STAT_MTIME)
		return stat.mtime;
	else
		return 0;
}

S_API bool S_CALLTYPE SteamAPI_ISteamRemoteStorage_GetQuota(intptr_t instancePtr, uint64* pnTotalBytes, uint64* puAvailableBytes) {
	*pnTotalBytes = 1024 * 1024 * 1024;
	size_t usage = 0;
	int64_t c = zip_get_num_entries(zip, NULL);
	for (int64_t i = 0; i < c; i++) {
		zip_stat_t stat;
		zip_stat_init(&stat);
		zip_stat_index(zip, i, 0, &stat);
		if (stat.valid & ZIP_STAT_SIZE)
			usage += static_cast<size_t>(stat.size);
	}
 	*puAvailableBytes = *pnTotalBytes-usage;
	return true;
}
S_API ERemoteStoragePlatform GetSyncPlatforms(intptr_t instancePtr, const char* pchFile) {
	return k_ERemoteStoragePlatformAll;
}
//to be continued