add_library(MathHelpers
        src/MathHelpers/hsl.cpp src/MathHelpers/hsl.h)

target_include_directories(MathHelpers
        PUBLIC
        src/
        ${DirectX_INCLUDE_DIRS})

target_link_libraries(MathHelpers ${DirectX_LIBRARIES})
target_link_directories(MathHelpers PUBLIC ${DirectX_LIBRARY_PATHS})
