#pragma once

#include <list>
#include <string>
#include <Windows.h>

struct ServerListEntry
{
	short id;
	std::string name;
	// may be incomplete. Capacity, State, Playercount is missing
};

class IClientNet
{
public:
	virtual void ConnectAs() = 0;
	virtual void Func_1() = 0;
	virtual void SendShardlistRequest() = 0;
	virtual void SendShardlistPing() = 0;
	virtual bool Login(LPCSTR lpString, LPCSTR lpPassword, char shardId, int a5) = 0;
	virtual void Func_5() = 0;
	virtual void Func_6() = 0;
	virtual void Func_7() = 0;
	virtual void Func_8() = 0;
	virtual void Func_9() = 0;
	virtual void Func_10() = 0;
	virtual void Func_11() = 0;
	virtual void Func_12() = 0;
	virtual void Func_13() = 0;
	virtual void Func_14() = 0;
	virtual std::list<ServerListEntry*>* Func_15() = 0;
	virtual void Func_16() = 0;
	virtual void Func_17() = 0;
	virtual void Func_18() = 0;
	virtual void Func_19() = 0;
	virtual void Func_20() = 0;
	virtual void Func_21() = 0;
	virtual void Func_22() = 0;
	virtual void Func_23() = 0;
	virtual void Func_24() = 0;
	virtual void Func_25() = 0;
	virtual void Func_26() = 0;
	virtual void Func_27() = 0;
	virtual void Func_28() = 0;
	virtual void Func_29() = 0;
	virtual void IBUV_confirm(const std::string& code) = 0;
	virtual int Func_31(int) = 0;
	virtual void destruct() = 0;
};
