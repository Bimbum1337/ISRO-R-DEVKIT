set(SOURCE_FILES src/hook.cpp)

add_library(memory STATIC ${SOURCE_FILES})
target_include_directories(memory
        PUBLIC include/
        PRIVATE include/memory)
