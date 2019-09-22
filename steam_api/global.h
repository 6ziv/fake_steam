#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define STEAM_API_EXPORTS
#include <steam_api.h>
#include <zip.h>
#include "calls.h"
#include <map>
#include <vector>
#include <set>
#include <array>
extern CallQueue queue;
extern HSteamUser user;
extern HSteamPipe pipe;
extern CSteamID uid;
extern uint32 appID;
extern zip_t* zip;
extern CallbackQueue callbacks;