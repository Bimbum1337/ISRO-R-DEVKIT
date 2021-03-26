#pragma once

#define HOOK_ORIGINAL_STATIC(address, newValue) \
    StaticAddressHook<address> hook_ ## address ((newValue));

template<unsigned int Address>
class StaticAddressHook {
public:
    explicit StaticAddressHook(const void *newValue) {
        static int count = 0;

        if (count != 0) {
            throw "Too many registrations";
        }

        count++;

        WriteToAddress(reinterpret_cast<void*>(Address), newValue);
    }

private:
    template<typename T>
    void WriteToAddress(void *address, T value) {
        DWORD dwProtect = 0;

        if (!VirtualProtect((LPVOID) address, sizeof(T), PAGE_EXECUTE_READWRITE, &dwProtect)) {
            perror("Failed to unprotect memory\n");
            return;
        }

        *reinterpret_cast<T*>(address) = value;

        DWORD otherProtect;
        if (!VirtualProtect((LPVOID) address, sizeof(T), dwProtect, &otherProtect)) {
            perror("Failed to restore protection on memory");
        }
    }
};
