#include "ICMonster.h"

void CICMonster::Func_15(int param_1, float* param_2) {
    printf("%s\n", __FUNCTION__);
    reinterpret_cast<void (__thiscall *)(const CICMonster *, int param_1, float *param_2)>(0x009d3e70)(this, param_1, param_2);
}

void CICMonster::Func_15_impl(int param_1, float* param_2) {
    CICMonster::Func_15(param_1, param_2);
}
