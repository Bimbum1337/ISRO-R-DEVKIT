#pragma once

#define HOOK_ORIGINAL_MEMBER(address, func) \
    MemberFunctionHook<address> hook_ ## address ((func));

template<unsigned int Address>
class MemberFunctionHook {
public:
    template<typename FuncPtr>
    explicit MemberFunctionHook(FuncPtr func) {
        static int count = 0;

        if (count != 0) {
            throw "Too many registrations";
        }

        count++;

        union {
            int address;
            FuncPtr ptr;
        } myu;

        myu.ptr = func;

        PlaceJump(Address, myu.address);
    }

private:
    void PlaceJump(int trampoline, int target) {
        unsigned char jmpInst[] = {0xE9, 0x00, 0x00, 0x00, 0x00};
        int distance;
        DWORD dwProtect = 0;

        distance = target - trampoline - 5;

        // Write jump-distance to instruction
        memcpy((jmpInst + 1), &distance, 4);

        if (!VirtualProtect((LPVOID) trampoline, sizeof(jmpInst), PAGE_EXECUTE_READWRITE, &dwProtect)) {
            perror("Failed to unprotect memory\n");
            return;
        }

        memcpy((LPVOID) trampoline, jmpInst, sizeof(jmpInst));

        DWORD otherProtect;
        if (!VirtualProtect((LPVOID) trampoline, sizeof(jmpInst), dwProtect, &otherProtect)) {
            perror("Failed to restore protection on memory");
        }
    }
};
