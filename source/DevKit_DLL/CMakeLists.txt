option(CONFIG_OLD_UNDERBAR "Turn the old EXP Bar ON/OFF" OFF)

if (CONFIG_OLD_UNDERBAR)
    add_definitions(-DCONFIG_OLD_UNDERBAR)
endif()

set(SOURCE_FILES
        src/DllMain.cpp
        src/GFXVideo3d_Hook.cpp
        src/GFXVideo3d_Hook.h
        src/Hooks.cpp
        src/Hooks.h
        src/IFflorian0.cpp
        src/IFflorian0.h
        src/ImGui_Windows.cpp
        src/ImGui_Windows.h
        src/StdAfx.cpp
        src/StdAfx.h
        src/Util.cpp
        src/Util.h
        src/WndProc.cpp
        src/WndProc.h
        src/CGame_Hook.cpp src/CGame_Hook.h
        src/QuickStart.cpp src/QuickStart.h)

add_library(DevKit_DLL SHARED ${SOURCE_FILES})
target_link_libraries(DevKit_DLL BSLib ClientLib memory winmm)

set_target_properties(DevKit_DLL
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/BinOut/${CMAKE_BUILD_TYPE}/"
        LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/BinOut/${CMAKE_BUILD_TYPE}/"
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/BinOut/${CMAKE_BUILD_TYPE}/"
        )
