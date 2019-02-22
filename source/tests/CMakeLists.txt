set(SOURCE_FILES
        src/main.cpp
        src/vc80-stl.cpp
        src/ClientLib.cpp)

add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests BSLib abi-testing)
