#pragma once

typedef void (*SetLogHandlerFn)(const char *);

#define BS_ASSERT(cond)

/// \brief Assertion with a message
/// \details Validates cond and throws an error with given message msg if cond is false
#define BS_ASSERT_MSG(cond, msg)

/// \summary Write a message to the console output
/// \address 0049d620
void Put(const char *fmt, ...);

/// \summary Write a message to the dump file
/// \address 0049d640
void PutDump(const char *fmt, ...);

/// \summary Set callback for storing messages set with PutDump
/// \address 0049d630
void SetPutDumpHandler(SetLogHandlerFn fn);

