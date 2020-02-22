set(SOURCE_FILES 
        src/ClientNet/MsgStreamBuffer.h
        src/ClientNet/MsgStreamBuffer.cpp
        src/ClientNet/IClientNet.h
        src/ClientNet/ClientNet.h
        src/ClientNet/ClientNet.cpp)

add_library(ClientNet INTERFACE)
target_include_directories(ClientNet INTERFACE src/)
