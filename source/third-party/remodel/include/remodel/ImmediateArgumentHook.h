#pragma once

#define HOOK_IMMEDIATE_ARG(address, newValue) \
    ImmediateArgumentHook<address> hook_ ## address ((newValue));

template<unsigned int Address>
class ImmediateArgumentHook {
    enum opcode : unsigned char {
        ADD_IMM32_REG32 = 0x01,
        OR_IMM32_REG32 = 0x09,

        AND_IMM32_REG32 = 0x21,
        SUB_IMM32_REG32 = 0x29,
        CMP_IMM32_REG32 = 0x39,
        CMP_REG32_IMM32 = 0x3b,

        AND_IMM32_IMM8 = 0x83,

        TEST_IMM8_REG8 = 0x84,

        MOV_IMM32_REG32 = 0x89,
        MOV_REG32_IMM32 = 0x8b,

        MOV_REG32_IMM32_2 = 0xa1,
        MOV_IMM32_REG32_2 = 0xa3,

        OP_TEST = 0xf6
    };
public:
    explicit ImmediateArgumentHook(const void *newValue) {
        static int count = 0;

        if (count != 0) {
            throw "Too many registrations";
        }

        count++;

        unsigned int offset = ArgumentOffset(GetOpcode(reinterpret_cast<const void *>(Address)));

        WriteToAddress(reinterpret_cast<void *>(Address + offset), newValue);
    }

private:
    template<typename T>
    void WriteToAddress(void *address, T value) {
        DWORD dwProtect = 0;

        if (!VirtualProtect((LPVOID) address, sizeof(T), PAGE_EXECUTE_READWRITE, &dwProtect)) {
            perror("Failed to unprotect memory\n");
            return;
        }

        *reinterpret_cast<T *>(address) = value;

        DWORD otherProtect;
        if (!VirtualProtect((LPVOID) address, sizeof(T), dwProtect, &otherProtect)) {
            perror("Failed to restore protection on memory");
        }
    }

    opcode GetOpcode(const void *address) const {
        return *reinterpret_cast<const opcode *>(address);
    }

    unsigned int ArgumentOffset(opcode op) const {
        switch (op) {
            case ADD_IMM32_REG32:
            case OR_IMM32_REG32:
            case OP_TEST:
            case AND_IMM32_REG32:
            case SUB_IMM32_REG32:
            case CMP_IMM32_REG32:
            case CMP_REG32_IMM32:
            case AND_IMM32_IMM8:
            case TEST_IMM8_REG8:
            case MOV_IMM32_REG32:
            case MOV_REG32_IMM32:
                return 2u;

            case MOV_REG32_IMM32_2:
            case MOV_IMM32_REG32_2:
                return 1u;

            default: {
                __debugbreak();
                return 0;
            }
        }
    }
};
