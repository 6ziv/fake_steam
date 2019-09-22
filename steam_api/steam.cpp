#include "global.h"
S_API bool S_CALLTYPE SteamAPI_Init() {

	srand(time(0));
	while(user==0)user = 111;
	while(pipe==0)pipe = rand();
	int tid = 0;
	while (tid == 0)tid = 222;
	uid.Set(tid, EUniverse::k_EUniversePublic, EAccountType::k_EAccountTypeIndividual);
	if (appID == 0)appID = rand();
	queue.clear();
	zip = zip_open("E:\\data.zip", ZIP_CREATE, NULL);
	return (zip != nullptr);
}
S_API void S_CALLTYPE SteamAPI_ReleaseCurrentThreadMemory() {
	queue.clear();
	return;
}
S_API bool S_CALLTYPE SteamAPI_RestartAppIfNecessary(uint32_t unOwnAppID) {
	appID = unOwnAppID;
	return false;
}
S_API void S_CALLTYPE SteamAPI_RunCallbacks() {
	queue.run();
	callbacks.run();
	return;
}
S_API void S_CALLTYPE SteamAPI_SetMiniDumpComment(const char* pchMsg) {
	return;
}
S_API void S_CALLTYPE SteamAPI_Shutdown() {
	queue.clear();
	return;
};
S_API void S_CALLTYPE SteamAPI_WriteMiniDump(uint32_t uStructuredExceptionCode, void* pvExceptionInfo, uint32_t uBuildID) {
	return;
}

S_API int32_t S_CALLTYPE GetHSteamPipe() {
	return pipe;
}
S_API int32_t S_CALLTYPE GetHSteamUser() {
	return user;
}

S_API int32_t S_CALLTYPE SteamAPI_GetHSteamPipe() {
	return pipe;
}
S_API int32_t S_CALLTYPE SteamAPI_GetHSteamUser() {
	return user;
}
S_API void S_CALLTYPE SteamAPI_RegisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall) {
	if (queue.contains(hAPICall)) {
		queue.set(hAPICall, pCallback);
	}
}
S_API void S_CALLTYPE SteamAPI_UnRegisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall) {
	if (queue.contains(hAPICall)) {
		queue.remove(hAPICall);
	}
}
class CCallbackMgr {
public:
	static void Reg(class CCallbackBase* pCallback, int iCallback) {
		pCallback->m_iCallback = iCallback;
		pCallback->m_nCallbackFlags |= pCallback->k_ECallbackFlagsRegistered;
	}
	static void UnReg(class CCallbackBase* pCallback) {
		pCallback->m_nCallbackFlags &= ~pCallback->k_ECallbackFlagsRegistered;
	}
};

S_API void S_CALLTYPE SteamAPI_RegisterCallback(class CCallbackBase* pCallback, int iCallback) {
	CCallbackMgr::Reg(pCallback, iCallback);
	callbacks.insert(iCallback, pCallback);
}
S_API void S_CALLTYPE SteamAPI_UnregisterCallback(class CCallbackBase* pCallback) {
	CCallbackMgr::UnReg(pCallback);
	callbacks.remove(pCallback);
}
