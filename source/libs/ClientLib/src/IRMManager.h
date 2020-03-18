#pragma once

#include <string>
#include <BSLib/BSLib.h>

// Resolve a circular dependency
class CIFWnd;

/// Loader for resinfo/*.txt files
class CIRMManager {
public:
    CIRMManager();

    /// Load a resinfo file from the PK2
    /// \param filename Path and filename in Media.pk2 to load. Example: "resinfo/file.txt"
    void LoadFromFile(const char *filename);

    /// Instantiate all controls in the named section
    /// \param section Name of the section to load. Example: "Create"
    /// \param base Pointer to the object to instantiate the controls in.
    void CreateInterfaceSection(std::string section, CObj *base);

    /// Get a pointer to a control identified by the Id
    /// \param id The Id of the control as stated in the resinfo file or set on creation
    /// \param a2 Completely unknown, is always 1
    /// \returns Pointer to the control, NULL if Id was not found.
    CIFWnd *GetResObj(int id, int a2);

    /// Get a pointer to a control identified by the Id
    /// \tparam T Expected type of the control. The type is never validated.
    /// \param id The Id of the control as stated in the resinfo file or set on creation
    /// \param a2 Completely unknown, is always 1
    /// \returns Pointer to the control, NULL if Id was not found.
    template<typename T>
    T *GetResObj(int id, int a2) {
        return reinterpret_cast<T *(__thiscall *)(CIRMManager *, int, int)>(0x008B51F0)(this, id, a2);
    }

private:
    std::n_map<int, void *> m_interfacemap;
    char _gap0[4];
    std::n_string m_str;
    int N00009CBC;
};
