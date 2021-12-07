add_library(TypeId STATIC include/TypeId.h src/TypeIdRegistry.cpp)

target_include_directories(TypeId PUBLIC include/)
