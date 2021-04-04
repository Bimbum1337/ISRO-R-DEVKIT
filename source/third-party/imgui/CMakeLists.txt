set(SOURCE_FILES
        imgui/imgui.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_draw.cpp
        imgui/examples/imgui_impl_dx9.cpp
        imgui/examples/imgui_impl_win32.cpp)

add_library(imgui STATIC ${SOURCE_FILES})
target_include_directories(imgui
        PUBLIC ./
        PRIVATE imgui/)

add_executable(imgui-demo-win32-dx9
        imgui/examples/example_win32_directx9/main.cpp
        imgui/imgui_demo.cpp)

target_link_libraries(imgui-demo-win32-dx9 imgui d3d9)

target_include_directories(imgui-demo-win32-dx9
        PRIVATE
        imgui/
        imgui/examples/)
