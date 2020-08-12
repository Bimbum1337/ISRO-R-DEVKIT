set(SOURCE_FILES 
        src/ClientNet/MsgStreamBuffer.h
        src/ClientNet/MsgStreamBuffer.cpp
        src/ClientNet/IClientNet.h
        src/ClientNet/ClientNet.h
        src/ClientNet/ClientNet.cpp)

add_library(ClientNet STATIC ${SOURCE_FILES})
target_link_libraries(ClientNet PUBLIC BSLib abi-testing remodel)
target_include_directories(ClientNet PUBLIC src/)
