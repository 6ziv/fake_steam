#include "global.h"

S_API bool S_CALLTYPE SteamAPI_ISteamUserStats_RequestCurrentStats(intptr_t instancePtr) {
	UserStatsReceived_t* data = reinterpret_cast<UserStatsReceived_t*>(malloc(sizeof(UserStatsReceived_t*)));
	data->m_steamIDUser = uid;
	data->m_eResult = k_EResultOK;
	data->m_nGameID = appID;
	callbacks.trigger(UserStatsReceived_t::k_iCallback, data);
	return true;
}
S_API uint32 S_CALLTYPE SteamAPI_ISteamUserStats_GetNumAchievements(intptr_t instancePtr) {
	return 0;
}