#include "calls.h"
_CCall::_CCall(bool _IOFailure, void* _pvdata, SteamAPICall_t _id) {
	IOFailure = _IOFailure;
	pvdata = _pvdata;
	id = _id;
	cb = nullptr;
}
_CCall::~_CCall() {
	if (pvdata) {
		try {
			free(pvdata);
		}
		catch (...) {}
	}
}
void _CCall::Set(CCallbackBase* _cb) {
	cb = _cb;
}
bool _CCall::Run() {
	if (cb == nullptr)return false;
	
	cb->Run(pvdata, IOFailure, id);
	cb->Run(pvdata);
	return true;
}

void CallQueue::clear() {
	calls.clear();
}
SteamAPICall_t CallQueue::insert(bool _IOF, void* _pvdata) {
	while ((calls.find(CallId) != calls.end()) || (CallId == 0))CallId++;
	calls[CallId] = std::make_unique<_CCall>(_IOF, _pvdata, CallId);
	return CallId;
}
bool CallQueue::contains(SteamAPICall_t ct) {
	return calls.find(ct) != calls.end();
}
void CallQueue::remove(SteamAPICall_t id) {
	calls.erase(id);
}
void CallQueue::set(SteamAPICall_t ct, CCallbackBase* _cb) {
	if (calls.find(ct) == calls.end())return;
	calls[ct]->Set(_cb);
}
void CallQueue::run() {
	for (auto i = calls.begin(); i != calls.end(); i++) {
		if(i->second->Run())
			calls.erase(i);
	}
}
_CB::_CB(CCallbackBase* _cb) {
	cb = _cb;
}
void _CB::Run(void* pvdata){
	cb->Run(pvdata);
}

void CallbackQueue::insert(int iCallback, CCallbackBase* pCallback){
	if (callbacks.find(iCallback) == callbacks.end())callbacks[iCallback] = std::set<CB>();
	callbacks[iCallback].insert(std::make_unique<_CB>(pCallback));
}
void CallbackQueue::remove(CCallbackBase* pCallback){
	int iCallback = pCallback->GetICallback();
	if (callbacks.find(iCallback) == callbacks.end())return;
	callbacks[iCallback].erase(std::make_unique<_CB>(pCallback));
}
void CallbackQueue::trigger(int iCallback, void* data){ 
	std::pair<int, void*> p(iCallback, data);
	active.push_back(p);
}
void CallbackQueue::run(){
	for (auto i = active.begin(); i != active.end(); i++) {
		if (callbacks.find(i->first) == callbacks.end())return;
		for (auto j = callbacks[i->first].begin(); j != callbacks[i->first].end(); j++) {
			try {
				(*j)->Run(i->second);
			}catch(...){}
		}
		try {
			free(i->second);
		}
		catch (...) {}
	}
}
