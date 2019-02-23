
set(SOURCE_FILES src/BSLib/_internal/_BSDynamic.h
    src/BSLib/_internal/_BSMsg.h
    src/BSLib/_internal/custom_stl.h
    src/BSLib/_internal/MemPoolManager.cpp
    src/BSLib/_internal/MemPoolManager.h
    src/BSLib/BSLib.cpp
    src/BSLib/BSLib.h)

add_library(BSLib STATIC ${SOURCE_FILES})
target_include_directories(BSLib PUBLIC src/)
target_link_libraries(BSLib ClientNet remodel)
