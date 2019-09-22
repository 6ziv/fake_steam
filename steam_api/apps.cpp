#include "global.h"

S_API bool SteamAPI_ISteamApps_BIsSubscribed(intptr_t instancePtr) {
	return true;
}
S_API bool SteamAPI_ISteamApps_BIsLowViolence(intptr_t instancePtr) {
	return false;
}
S_API bool SteamAPI_ISteamApps_BIsCybercafe(intptr_t instancePtr) {
	return false;
}
S_API bool SteamAPI_ISteamApps_BIsVACBanned(intptr_t instancePtr) {
	return false;
}
S_API const char* SteamAPI_ISteamApps_GetCurrentGameLanguage(intptr_t instancePtr) {
	return "schinese";
}
S_API const char* SteamAPI_ISteamApps_GetAvailableGameLanguages(intptr_t instancePtr) {
	return "schinese";
}
S_API bool SteamAPI_ISteamApps_BIsSubscribedApp(intptr_t instancePtr, AppId_t appId) {
	return (appID == appId);
}
S_API bool SteamAPI_ISteamApps_BIsDlcInstalled(intptr_t instancePtr, AppId_t appID) {
	return false;
}
S_API uint32 SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime(intptr_t instancePtr, AppId_t nAppID) {
	return 926956800;
}
S_API bool SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend(intptr_t instancePtr) {
	return false;
}
S_API int SteamAPI_ISteamApps_GetDLCCount(intptr_t instancePtr) {
	return 0;
}
S_API bool SteamAPI_ISteamApps_BGetDLCDataByIndex(intptr_t instancePtr, int iDLC, AppId_t* pAppID, bool* pbAvailable, char* pchName, int cchNameBufferSize) {
	return false;
}
S_API void SteamAPI_ISteamApps_InstallDLC(intptr_t instancePtr, AppId_t nAppID) {
}
S_API void SteamAPI_ISteamApps_UninstallDLC(intptr_t instancePtr, AppId_t nAppID) {
}
S_API void SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey(intptr_t instancePtr, AppId_t nAppID);
S_API bool SteamAPI_ISteamApps_GetCurrentBetaName(intptr_t instancePtr, char* pchName, int cchNameBufferSize) {
	return false;
}
S_API bool SteamAPI_ISteamApps_MarkContentCorrupt(intptr_t instancePtr, bool bMissingFilesOnly) {
	return false;
}
S_API uint32 SteamAPI_ISteamApps_GetInstalledDepots(intptr_t instancePtr, AppId_t appID, DepotId_t* pvecDepots, uint32 cMaxDepots) {
	return 0;
}
S_API uint32 SteamAPI_ISteamApps_GetAppInstallDir(intptr_t instancePtr, AppId_t appId, char* pchFolder, uint32 cchFolderBufferSize) {
	//make up a fake path
	if (appId == appID) {
		//for current process:use current dir
		char path[MAX_PATH];
		GetModuleFileNameA(0, path, MAX_PATH);
		size_t l = strnlen_s(path, MAX_PATH);
		l--;
		while (l > 0 && path[l] != '\\') {
			path[l] = '\0';
		}
		if (cchFolderBufferSize > l) {
			strcpy(pchFolder, path);
			return static_cast<uint32>(l);
		}
		else {
			return 0;
		}
	}
	else {
		char path[MAX_PATH];
		sprintf(path, "C:\\Program Files\\Steam\\steamapps\\common\\%08x", appID);
		if (cchFolderBufferSize > strlen(path)) {
			strcpy(pchFolder, path);
			return static_cast<uint32>(strlen(path));
		}
		else return 0;
	}
}
S_API bool SteamAPI_ISteamApps_BIsAppInstalled(intptr_t instancePtr, AppId_t appId) {
	return (appID == appId);
}
S_API uint64 SteamAPI_ISteamApps_GetAppOwner(intptr_t instancePtr) {
	return uid.ConvertToUint64();
}
S_API const char* SteamAPI_ISteamApps_GetLaunchQueryParam(intptr_t instancePtr, const char* pchKey) {
	return "";
}
S_API bool SteamAPI_ISteamApps_GetDlcDownloadProgress(intptr_t instancePtr, AppId_t nAppID, uint64* punBytesDownloaded, uint64* punBytesTotal) {
	return false;
}
S_API int SteamAPI_ISteamApps_GetAppBuildId(intptr_t instancePtr) {
	return 0;
}
S_API void SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys(intptr_t instancePtr) {
}
S_API SteamAPICall_t SteamAPI_ISteamApps_GetFileDetails(intptr_t instancePtr, const char* pszFileName) {
	FileDetailsResult_t* filedetail = reinterpret_cast<FileDetailsResult_t*>(malloc(sizeof(FileDetailsResult_t)));
	filedetail->m_eResult = k_EResultFileNotFound;
	return queue.insert(false, filedetail);
}
S_API int SteamAPI_ISteamApps_GetLaunchCommandLine(intptr_t instancePtr, char* pszCommandLine, int cubCommandLine) {
	return sprintf_s(pszCommandLine,cubCommandLine, "steam://run/%08x", appID);
}
S_API bool SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing(intptr_t instancePtr) {
	return false;
}
S_API void* S_CALLTYPE SteamInternal_CreateInterface(const char* ver) {
	return (void*)1;
}