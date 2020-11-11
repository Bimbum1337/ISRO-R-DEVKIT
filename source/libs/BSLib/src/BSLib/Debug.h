#pragma once

/// \file

typedef void (*LogHandlerFn)(const char *);

typedef void (*AssertHandlerFn)(int, const char *, const char *);

/// \brief Assertion with a message
/// \details Validates cond and throws an error with given message msg if cond is false
#define BS_ASSERT_MSG(cond, msg, ...)                                                             \
    do {                                                                                          \
        if (!(cond)) {                                                                            \
            if (!reinterpret_cast<bool(*)(int, const char *, const char *, ...)>(0x0049e490)(     \
        __LINE__, __FILE__, (msg), __VA_ARGS__)) {                                                \
            __debugbreak();                                                                       \
        }}} while (0)


#define _BS_STRINGIFY_HELPER(text) #text

/// \brief Converts an expression to a string
#define BS_STRINGIFY(expr) _BS_STRINGIFY_HELPER(expr)

/// \brief Assertion
/// \details Validates cond and throws an error if cond is false
#define BS_ASSERT(cond) BS_ASSERT_MSG(cond, BS_STRINGIFY(cond))

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

/// \def BS_DEBUG_LOW(fmt, ...)
/// \copybrief PUT_DEBUG_LOW
#if PUT_LOGLEVEL <= PUT_DEBUG_LOW
#define BS_DEBUG_LOW(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_DEBUG_LOW(fmt, ...)
#endif

/// \def BS_DEBUG(fmt, ...)
/// \copybrief PUT_DEBUG
#if PUT_LOGLEVEL <= PUT_DEBUG
#define BS_DEBUG(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_DEBUG(fmt, ...)
#endif

/// \def BS_INFO(fmt, ...)
/// \copybrief PUT_INFO
#if PUT_LOGLEVEL <= PUT_INFO
#define BS_INFO(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_INFO(fmt, ...)
#endif

/// \def BS_WARNING(fmt, ...)
/// \copybrief PUT_WARNING
#if PUT_LOGLEVEL <= PUT_WARNING
#define BS_WARNING(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_WARNING(fmt, ...)
#endif

/// \def BS_ERROR(fmt, ...)
/// \copybrief PUT_ERROR
#if PUT_LOGLEVEL <= PUT_ERROR
#define BS_ERROR(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_ERROR(fmt, ...)
#endif

/// \def BS_CRITICAL(fmt, ...)
/// \copybrief PUT_CRITICAL
#if PUT_LOGLEVEL <= PUT_CRITICAL
#define BS_CRITICAL(fmt, ...) do { Put(fmt, __VA_ARGS__);} while (0);
#else
#define BS_CRITICAL(fmt, ...)
#endif

/// \brief Write a message to the console output
/// \attention Please consider using macros instead of calling this function directly
/// \see BS_DEBUG_LOW \see BS_DEBUG \see BS_INFO \see BS_WARNING \see BS_ERROR \see BS_CRITICAL
/// \address 0049d620
void Put(const char *fmt, ...);

/// \brief Write a message to the dump file
/// \address 0049d640
void PutDump(const char *fmt, ...);

/// \brief Set callback for storing messages set with PutDump
/// \address 0049d630
void SetPutDumpHandler(LogHandlerFn fn);

/// \brief Set callback for handling assertions
/// \address 0049e470
void SetAssertHandler(AssertHandlerFn fn);
