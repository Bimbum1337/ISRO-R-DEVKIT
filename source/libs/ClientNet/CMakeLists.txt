set(SOURCE_FILES src/ClientNet/MsgStreamBuffer.h)

add_library(ClientNet INTERFACE)
target_include_directories(ClientNet INTERFACE src/)
