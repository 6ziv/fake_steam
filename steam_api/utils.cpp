#include "global.h"
S_API uint32 SteamAPI_ISteamUtils_GetSecondsSinceAppActive(intptr_t instancePtr) {
	return 0;
}
S_API uint32 SteamAPI_ISteamUtils_GetSecondsSinceComputerActive(intptr_t instancePtr) {
	return 0;
}
S_API EUniverse SteamAPI_ISteamUtils_GetConnectedUniverse(intptr_t instancePtr) {
	return EUniverse::k_EUniversePublic;
}
S_API uint32 SteamAPI_ISteamUtils_GetServerRealTime(intptr_t instancePtr) {
	return time(0);
}
S_API const char* SteamAPI_ISteamUtils_GetIPCountry(intptr_t instancePtr) {
	return "cn";
}
S_API bool SteamAPI_ISteamUtils_GetCSERIPPort(intptr_t instancePtr, uint32* unIP, uint16* usPort) {
	return false;
}
S_API uint8 SteamAPI_ISteamUtils_GetCurrentBatteryPower(intptr_t instancePtr) {
	SYSTEM_POWER_STATUS ps;
	if (!GetSystemPowerStatus(&ps))return 255;
	return ps.BatteryLifePercent;
}
S_API uint32 SteamAPI_ISteamUtils_GetAppID(intptr_t instancePtr) {
	return appID;
}
S_API void SteamAPI_ISteamUtils_SetOverlayNotificationPosition(intptr_t instancePtr, ENotificationPosition eNotificationPosition) {
	return;
}
S_API bool SteamAPI_ISteamUtils_IsAPICallCompleted(intptr_t instancePtr, SteamAPICall_t hSteamAPICall, bool* pbFailed) {
	return true;
}
S_API ESteamAPICallFailure SteamAPI_ISteamUtils_GetAPICallFailureReason(intptr_t instancePtr, SteamAPICall_t hSteamAPICall) {
	return k_ESteamAPICallFailureInvalidHandle;
}
S_API bool SteamAPI_ISteamUtils_GetAPICallResult(intptr_t instancePtr, SteamAPICall_t hSteamAPICall, void* pCallback, int cubCallback, int iCallbackExpected, bool* pbFailed) {
	return false;
}
S_API uint32 SteamAPI_ISteamUtils_GetIPCCallCount(intptr_t instancePtr) {
	return 0;
}
S_API void SteamAPI_ISteamUtils_SetWarningMessageHook(intptr_t instancePtr, SteamAPIWarningMessageHook_t pFunction) {
	return;
}
S_API bool SteamAPI_ISteamUtils_IsOverlayEnabled(intptr_t instancePtr) {
	return false;
}
S_API bool SteamAPI_ISteamUtils_BOverlayNeedsPresent(intptr_t instancePtr) {
	return false;
}
S_API SteamAPICall_t SteamAPI_ISteamUtils_CheckFileSignature(intptr_t instancePtr, const char* szFileName) {
	CheckFileSignature_t* data = reinterpret_cast<CheckFileSignature_t*>(malloc(sizeof(CheckFileSignature_t)));
	if (data == NULL)return 0;
	data->m_eCheckFileSignature = k_ECheckFileSignatureValidSignature;
	return queue.insert(false, data);
}
S_API bool SteamAPI_ISteamUtils_ShowGamepadTextInput(intptr_t instancePtr, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char* pchDescription, uint32 unCharMax, const char* pchExistingText) {
	return false;
}
S_API uint32 SteamAPI_ISteamUtils_GetEnteredGamepadTextLength(intptr_t instancePtr) {
	return 0;
}
S_API bool SteamAPI_ISteamUtils_GetEnteredGamepadTextInput(intptr_t instancePtr, char* pchText, uint32 cchText) {
	return false;
}
S_API const char* SteamAPI_ISteamUtils_GetSteamUILanguage(intptr_t instancePtr) {
	return "schinese";
}
S_API bool SteamAPI_ISteamUtils_IsSteamRunningInVR(intptr_t instancePtr) {
	return false;
}
S_API void SteamAPI_ISteamUtils_SetOverlayNotificationInset(intptr_t instancePtr, int nHorizontalInset, int nVerticalInset) {
	return;
}
S_API bool SteamAPI_ISteamUtils_IsSteamInBigPictureMode(intptr_t instancePtr) {
	return false;
}
S_API void SteamAPI_ISteamUtils_StartVRDashboard(intptr_t instancePtr) {
	return;
}
S_API bool SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled(intptr_t instancePtr) {
	return false;
}
S_API void SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled(intptr_t instancePtr, bool bEnabled) {
	return;
}
S_API bool SteamAPI_ISteamUtils_IsSteamChinaLauncher(intptr_t instancePtr) {
	return false;
}
S_API bool SteamAPI_ISteamUtils_InitFilterText(intptr_t instancePtr) {
	return false;
}
S_API int SteamAPI_ISteamUtils_FilterText(intptr_t instancePtr, char* pchOutFilteredText, uint32 nByteSizeOutFilteredText, const char* pchInputMessage, bool bLegalOnly) {
	strcpy_s(pchOutFilteredText, nByteSizeOutFilteredText, pchInputMessage);
	return strnlen_s(pchOutFilteredText, nByteSizeOutFilteredText);
}

