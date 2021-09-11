
set(SOURCE_FILES src/GFXMainFrame/EntityManager.h
        src/GFXMainFrame/GFXMainFrame.cpp src/GFXMainFrame/GFXMainFrame.h
        src/GFXMainFrame/GWnd.cpp src/GFXMainFrame/GWnd.h
        src/GFXMainFrame/GWndBase.cpp src/GFXMainFrame/GWndBase.h
        src/GFXMainFrame/Process.cpp src/GFXMainFrame/Process.h
        src/GFXMainFrame/Camera.cpp src/GFXMainFrame/Camera.h)

add_library(GFXMainFrame STATIC ${SOURCE_FILES})
target_include_directories(GFXMainFrame PUBLIC src/)
target_link_libraries(GFXMainFrame BSLib ghidra)
