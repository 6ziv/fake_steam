#define _CRT_SECURE_NO_WARNINGS
#define STEAM_API_EXPORTS
#include <steam_api.h>
#include <random>
#include <time.h>
#include <Windows.h>
#include <map>
#include <set>
#include <memory>
#pragma once
class _CCall {
public:
	_CCall(bool _IOF, void* _pvdata, SteamAPICall_t _id);
	~_CCall();
	bool Run();
	void Set(CCallbackBase* _cb);
private:
	CCallbackBase* cb;
	bool IOFailure;
	void* pvdata;
	SteamAPICall_t id;
};
typedef std::unique_ptr<_CCall> CCall;
class CallQueue {
public:
	void clear();
	SteamAPICall_t insert(bool _IOF, void* _pvdata);
	void remove(SteamAPICall_t id);
	void set(SteamAPICall_t ct, CCallbackBase* _cb);
	bool contains(SteamAPICall_t ct);
	void run();
private:
	std::map<SteamAPICall_t, CCall> calls;
	SteamAPICall_t CallId;
};

class _CB {
public:
	_CB(CCallbackBase* _cb);
	void Run(void *pvdata);
private:
	CCallbackBase* cb;
};
typedef std::unique_ptr<_CB> CB;
class CallbackQueue {
public:
	void insert(int iCallback, CCallbackBase* pCallback);
	void remove(CCallbackBase* pCallback);
	void trigger(int iCallback, void* data);
	void run();
private:
	std::map<int, std::set<CB>> callbacks;
	std::vector<std::pair<int, void*>> active;
};
