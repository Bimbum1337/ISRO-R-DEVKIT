#include "Debug.h"

#include <cstdio>
#include <cstdarg>

#if 0
static LogHandlerFn logCallbackFn;
#else
#define logCallbackFn (*(LogHandlerFn*)0x0111a048)
#endif

#if 0
static AssertHandlerFn assertCallbackFn
#else
#define assertCallbackFn (*(AssertHandlerFn*)0x0111a080)
#endif


void Put(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vprintf(fmt, args);
    putchar('\n');
}

void PutDump(const char *fmt, ...) {
    char buffer[1024] = {0};

    if (!logCallbackFn)
        return;

    va_list args;
    va_start(args, fmt);

    int count = vsnprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, fmt, args);

    if ((count < 0) || (0x3ff <= count)) {
        buffer[1023] = '\0';
    }

    logCallbackFn(buffer);
}

void SetPutDumpHandler(LogHandlerFn fn) {
    logCallbackFn = fn;
}

void SetAssertHandler(AssertHandlerFn fn) {
    assertCallbackFn = fn;
}

