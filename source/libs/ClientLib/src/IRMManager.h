#pragma once
#pragma once
#include <string>
#include <BSLib/BSLib.h>
class CIFWnd;
class CIRMManager;

class CIRMManager
{
	
public:
	CIRMManager();

	void LoadFromFile(const char *filename);
	void CreateInterfaceSection(std::string section, CObj* base);
	CIFWnd* GetResObj(int id, int a2);

	template<typename T>
	T* GetResObj(int id, int a2);

private:
	std::n_map<int, void*> m_interfacemap;
	char _gap0[4];
	std::n_string m_str;
	int N00009CBC;
};

template <typename T>
T* CIRMManager::GetResObj(int id, int a2)
{
	return reinterpret_cast<T*>(GetResObj(id, a2));
}
