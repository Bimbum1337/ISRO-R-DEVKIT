set(SOURCE_FILES src/IFileManager.cpp)

add_library(GFXFileManagerLIB STATIC ${SOURCE_FILES})
target_include_directories(GFXFileManagerLIB
        PUBLIC include/
        PRIVATE include/GFXFileManagerLIB)
