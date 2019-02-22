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
