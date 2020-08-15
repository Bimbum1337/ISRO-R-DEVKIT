

set(SOURCE_FILES
        src/DllMain.cpp
        src/hooks/GFXVideo3d_Hook.cpp
        src/hooks/GFXVideo3d_Hook.h
        src/hooks/Hooks.cpp
        src/hooks/Hooks.h
        src/IFflorian0.cpp
        src/IFflorian0.h
        src/imgui_windows/ImGui_Windows.cpp src/imgui_windows/ImGui_Windows.h
        src/imgui_windows/InterfaceDebugger.cpp src/imgui_windows/InterfaceDebugger.h
        src/imgui_windows/SoundTool.cpp src/imgui_windows/SoundTool.h
        src/imgui_windows/NavMeshTool.cpp src/imgui_windows/NavMeshTool.h
        src/imgui_windows/EntityExplorer.cpp src/imgui_windows/EntityExplorer.h
        src/imgui_windows/NotificationTool.cpp src/imgui_windows/NotificationTool.h
        src/Util.cpp
        src/Util.h
        src/WndProc.cpp
        src/WndProc.h
        src/hooks/CGame_Hook.cpp src/hooks/CGame_Hook.h
        src/QuickStart.cpp src/QuickStart.h)

add_library(DevKit_DLL SHARED ${SOURCE_FILES})
target_link_libraries(DevKit_DLL BSLib ClientLib memory winmm)

set_target_properties(DevKit_DLL
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/BinOut/${CMAKE_BUILD_TYPE}/"
        LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/BinOut/${CMAKE_BUILD_TYPE}/"
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/BinOut/${CMAKE_BUILD_TYPE}/"
        )
