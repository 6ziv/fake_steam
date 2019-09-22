#include "global.h"
S_API HSteamUser S_CALLTYPE SteamAPI_ISteamUser_GetHSteamUser(intptr_t instancePtr) {
	return user;
}
S_API bool S_CALLTYPE SteamAPI_ISteamUser_BLoggedOn(intptr_t instancePtr) {
	return false;
}
S_API uint64 SteamAPI_ISteamUser_GetSteamID(intptr_t instancePtr) {
	return uid.ConvertToUint64();
}
S_API int SteamAPI_ISteamUser_InitiateGameConnection(intptr_t instancePtr, void* pAuthBlob, int cbMaxAuthBlob, class CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure) {
	return 2048;
}
S_API void SteamAPI_ISteamUser_TerminateGameConnection(intptr_t instancePtr, uint32 unIPServer, uint16 usPortServer) {
	return;
}
S_API void SteamAPI_ISteamUser_TrackAppUsageEvent(intptr_t instancePtr, class CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo) {
	return;
}
S_API bool SteamAPI_ISteamUser_GetUserDataFolder(intptr_t instancePtr, char* pchBuffer, int cubBuffer) {
	return false;//Deprecated
}
S_API void SteamAPI_ISteamUser_StartVoiceRecording(intptr_t instancePtr) {
	return;
}
S_API void SteamAPI_ISteamUser_StopVoiceRecording(intptr_t instancePtr) {
	return;
}
S_API EVoiceResult SteamAPI_ISteamUser_GetAvailableVoice(intptr_t instancePtr, uint32* pcbCompressed, uint32* pcbUncompressed_Deprecated, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) {
	return k_EVoiceResultNotInitialized;
}
S_API EVoiceResult SteamAPI_ISteamUser_GetVoice(intptr_t instancePtr, bool bWantCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten, bool bWantUncompressed_Deprecated, void* pUncompressedDestBuffer_Deprecated, uint32 cbUncompressedDestBufferSize_Deprecated, uint32* nUncompressBytesWritten_Deprecated, uint32 nUncompressedVoiceDesiredSampleRate_Deprecated) {
	return k_EVoiceResultNotInitialized;
}
S_API EVoiceResult SteamAPI_ISteamUser_DecompressVoice(intptr_t instancePtr, const void* pCompressed, uint32 cbCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten, uint32 nDesiredSampleRate) {
	return k_EVoiceResultNotInitialized;
}
S_API uint32 SteamAPI_ISteamUser_GetVoiceOptimalSampleRate(intptr_t instancePtr) {
	return 48000;
}
S_API HAuthTicket SteamAPI_ISteamUser_GetAuthSessionTicket(intptr_t instancePtr, void* pTicket, int cbMaxTicket, uint32* pcbTicket) {
	return k_HAuthTicketInvalid;
}
S_API EBeginAuthSessionResult SteamAPI_ISteamUser_BeginAuthSession(intptr_t instancePtr, const void* pAuthTicket, int cbAuthTicket, class CSteamID steamID) {
	return k_EBeginAuthSessionResultOK;
}
S_API void SteamAPI_ISteamUser_EndAuthSession(intptr_t instancePtr, class CSteamID steamID) {
	return;
}
S_API void SteamAPI_ISteamUser_CancelAuthTicket(intptr_t instancePtr, HAuthTicket hAuthTicket) {
	return;
}
S_API EUserHasLicenseForAppResult SteamAPI_ISteamUser_UserHasLicenseForApp(intptr_t instancePtr, class CSteamID steamID, AppId_t appID) {
	return k_EUserHasLicenseResultNoAuth;
}
S_API bool SteamAPI_ISteamUser_BIsBehindNAT(intptr_t instancePtr) {
	return false;
}
S_API void SteamAPI_ISteamUser_AdvertiseGame(intptr_t instancePtr, class CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer) {
	return;
}
S_API SteamAPICall_t SteamAPI_ISteamUser_RequestEncryptedAppTicket(intptr_t instancePtr, void* pDataToInclude, int cbDataToInclude) {
	EncryptedAppTicketResponse_t* data = reinterpret_cast<EncryptedAppTicketResponse_t*>(malloc(sizeof(EncryptedAppTicketResponse_t)));
	data->m_eResult = k_EResultNoConnection;
	return queue.insert(false, data);
}
S_API bool SteamAPI_ISteamUser_GetEncryptedAppTicket(intptr_t instancePtr, void* pTicket, int cbMaxTicket, uint32* pcbTicket) {
	return false;
}
S_API int SteamAPI_ISteamUser_GetGameBadgeLevel(intptr_t instancePtr, int nSeries, bool bFoil) {
	return 0;
}
S_API int SteamAPI_ISteamUser_GetPlayerSteamLevel(intptr_t instancePtr) {
	return 1000;
}
S_API SteamAPICall_t SteamAPI_ISteamUser_RequestStoreAuthURL(intptr_t instancePtr, const char* pchRedirectURL) {
	return k_uAPICallInvalid;
}
S_API bool SteamAPI_ISteamUser_BIsPhoneVerified(intptr_t instancePtr) {
	return true;
}
S_API bool SteamAPI_ISteamUser_BIsTwoFactorEnabled(intptr_t instancePtr) {
	return true;
}
S_API bool SteamAPI_ISteamUser_BIsPhoneIdentifying(intptr_t instancePtr) {
	return false;
}
S_API bool SteamAPI_ISteamUser_BIsPhoneRequiringVerification(intptr_t instancePtr) {
	return false;
}