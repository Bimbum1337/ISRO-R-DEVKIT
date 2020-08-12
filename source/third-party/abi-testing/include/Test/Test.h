#pragma once

#include <cstdlib>
#include <cstddef>

#define STRING(s) #s

#define ENSURE_OFFSET(parameter, offset) \
    int  __offset ## parameter [ offsetof(T, parameter) == offset ? 1 : -1 ];

#define ENSURE_SIZE(size) \
    int __sizeof [ sizeof (T) == size ? 1 : -1 ];

#define BEGIN_FIXTURE() \
private:                \
    template<typename T> \
    class TestFixture {


#define END_FIXTURE() };

#define RUN_FIXTURE(cls) \
    static void _RunFixture() { static cls :: TestFixture < cls > testFixture; }


#define check_size(class_name, sz) \
    check_size_tpl<class_name, sz>(STRING(class_name))

template<typename T, std::size_t expected_size>
bool check_size_tpl(const char *class_name) {
    bool size_ok = sizeof(T) == expected_size;
    printf("[%s] sizeof(%s) 0x%X %s 0x%X\n", size_ok ? "OK" : "FAIL", class_name, sizeof(T), size_ok ? "==" : "!=",
           expected_size);
    return size_ok;
}
