#pragma once

template<typename T>
int addr_from_this(T funptr) {
	union  {
		int addr;
		T ptr;
	} myu;

	myu.ptr = funptr;
	return myu.addr;
}


template<typename T>
void placeHook(int trampoline_location, T& target_location)
{
	placeHook(trampoline_location, reinterpret_cast<int>(&target_location));
}

void placeHook(int trampoline_location, int target_location);

void replaceOffset(int trampoline_location, int target_location);

void replaceAddr(int addr, int value);

void vftableHook(unsigned int vftable_addr, int offset, int target_func);

void JMPFunction(int address, int jumpto);

void RenderJMPInstruction(int address, int jumpto, char* buf);

bool SetNop(void* addr, int count);