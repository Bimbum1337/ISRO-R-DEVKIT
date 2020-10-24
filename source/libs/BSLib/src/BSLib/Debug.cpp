#include "Debug.h"

#include <cstdio>
#include <cstdarg>

#if 0
static SetLogHandlerFn callbackFn;
#else
#define callbackFn (*(SetLogHandlerFn*)0x0111a048)
#endif

void Put(const char *fmt, ...) {
}

void PutDump(const char *fmt, ...) {
    char buffer[1024] = {0};

    if (!callbackFn)
        return;

    va_list args;
    va_start(args, fmt);

    int count = vsnprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, fmt, args);

    if ((count < 0) || (0x3ff <= count)) {
        buffer[1023] = '\0';
    }

    callbackFn(buffer);
}

void SetPutDumpHandler(SetLogHandlerFn fn) {
    callbackFn = fn;
}
