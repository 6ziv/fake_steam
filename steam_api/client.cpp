#include "global.h"
S_API HSteamPipe SteamAPI_ISteamClient_CreateSteamPipe(intptr_t instancePtr) {
	return 1;
}
S_API bool SteamAPI_ISteamClient_BReleaseSteamPipe(intptr_t instancePtr, HSteamPipe hSteamPipe) {
	return true;
}
S_API HSteamUser SteamAPI_ISteamClient_ConnectToGlobalUser(intptr_t instancePtr, HSteamPipe hSteamPipe) {
	return user;
}
S_API HSteamUser SteamAPI_ISteamClient_CreateLocalUser(intptr_t instancePtr, HSteamPipe* phSteamPipe, EAccountType eAccountType) {
	return 1;
	//Server only.
}
S_API void SteamAPI_ISteamClient_ReleaseUser(intptr_t instancePtr, HSteamPipe hSteamPipe, HSteamUser hUser) {
	return;
}
S_API void SteamAPI_ISteamClient_SetWarningMessageHook(intptr_t instancePtr, SteamAPIWarningMessageHook_t pFunction) {
	return;
}
S_API bool SteamAPI_ISteamClient_BShutdownIfAllPipesClosed(intptr_t instancePtr) {
	return false;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamUser(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)1;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamFriends(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)2;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamUtils(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)3;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamMatchmaking(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)4;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamMatchmakingServers(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)5;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamUserStats(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)6;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamAppList(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)7;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamApps(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)8;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamController(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)9;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamGameServerStats(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)10;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamGenericInterface(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)11;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamHTMLSurface(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)12;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamHTTP(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)13;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamInventory(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)14;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamMusic(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)15;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamMusicRemote(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)16;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamNetworking(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)17;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamParentalSettings(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)18;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamRemoteStorage(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)19;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamScreenshots(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)20;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamUGC(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)21;
}
S_API void* S_CALLTYPE SteamAPI_ISteamClient_GetISteamVideo(int32_t hSteamUser, int32_t hSteamPipe, const char* pchVersion) {
	return (void*)22;
}
