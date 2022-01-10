
set(SOURCE_FILES src/BSLib/_internal/_BSDynamic.h
    src/BSLib/_internal/_BSMsg.h
    src/BSLib/_internal/custom_stl.h
    src/BSLib/_internal/MemPoolManager.cpp
    src/BSLib/_internal/MemPoolManager.h
    src/BSLib/BSLib.cpp src/BSLib/BSLib.h
    src/BSLib/MsgHandler.cpp src/BSLib/MsgHandler.h
    src/BSLib/multibyte.cpp src/BSLib/multibyte.h
    src/BSLib/memory/MemPool.h
    src/BSLib/StringCheck.cpp src/BSLib/StringCheck.h
    src/BSLib/Debug.h src/BSLib/Debug.cpp ../SimpleViewer/include/SimpleViewer/VBDynamic.h)

add_library(BSLib STATIC ${SOURCE_FILES})
target_include_directories(BSLib PUBLIC src/)
target_link_libraries(BSLib ClientNet remodel)
