#pragma once

typedef void (*LogHandlerFn)(const char *);

typedef void (*AssertHandlerFn)(int, const char *, const char *);

#define BS_ASSERT(cond)

/// \brief Assertion with a message
/// \details Validates cond and throws an error with given message msg if cond is false
#define BS_ASSERT_MSG(cond, msg)

/// Critical error that could lead to a crash
#define PUT_CRITICAL 5

/// Non-cricital error that will not lead to a crash
#define PUT_ERROR 4

/// A warning that should be taken care of
#define PUT_WARNING 3

/// Informational message that requires no action
#define PUT_INFO 2

/// Debugging message for developers
#define PUT_DEBUG 1

/// Low level debug messages for developers (consider enabling this on a per-file basis to avoid spam)
#define PUT_DEBUG_LOW 0

#ifndef PUT_LOGLEVEL_DEFAULT
#define PUT_LOGLEVEL_DEFAULT PUT_WARNING
#endif

#ifndef PUT_LOGLEVEL
#define PUT_LOGLEVEL PUT_LOGLEVEL_DEFAULT
#endif

#if PUT_LOGLEVEL <= PUT_DEBUG_LOW
#define BS_DEBUG_LOW(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_DEBUG_LOW(fmt, ...)
#endif

#if PUT_LOGLEVEL <= PUT_DEBUG
#define BS_DEBUG(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_DEBUG(fmt, ...)
#endif

#if PUT_LOGLEVEL <= PUT_INFO
#define BS_INFO(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_INFO(fmt, ...)
#endif

#if PUT_LOGLEVEL <= PUT_WARNING
#define BS_WARNING(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_WARNING(fmt, ...)
#endif

#if PUT_LOGLEVEL <= PUT_ERROR
#define BS_ERROR(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_ERROR(fmt, ...)
#endif

#if PUT_LOGLEVEL <= PUT_CRITICAL
#define BS_CRITICAL(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_CRITICAL(fmt, ...)
#endif

/// \summary Write a message to the console output
/// Please consider using macros instead of calling this function directly
/// \see BS_DEBUG_LOW \see BS_DEBUG \see BS_INFO \see BS_BS_WARNING \see BS_ERROR \see BS_CRITICAL
/// \address 0049d620
void Put(const char *fmt, ...);

/// \summary Write a message to the dump file
/// \address 0049d640
void PutDump(const char *fmt, ...);

/// \summary Set callback for storing messages set with PutDump
/// \address 0049d630
void SetPutDumpHandler(LogHandlerFn fn);

/// \summary Set callback for handling assertions
/// \address 0049e470
void SetAssertHandler(AssertHandlerFn fn);
