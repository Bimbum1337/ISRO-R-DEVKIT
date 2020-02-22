#include "ClientNet.h"

#if 0
bool CClientNet::Login(LPCSTR lpString, LPCSTR lpPassword, char shardId, int a5)
{
	//printf("Username: %s", lpString);
	//printf("Password: %s", lpPassword);

	// call original login function
	return reinterpret_cast<bool(__thiscall*)(CClientNet*, LPCSTR, LPCSTR, char, int)>(0x004C9290)(this, lpString, lpPassword, shardId, a5);
}
#endif
