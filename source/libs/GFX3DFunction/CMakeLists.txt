set(SOURCE_FILES
        src/GFX3DFunction/DrawingHelpers.cpp src/GFX3DFunction/DrawingHelpers.h
        src/GFX3DFunction/GFontTexture.cpp src/GFX3DFunction/GFontTexture.h
        src/GFX3DFunction/GFXVideo3d.cpp src/GFX3DFunction/GFXVideo3d.h
        src/GFX3DFunction/Common/d3dapp.cpp src/GFX3DFunction/Common/d3dapp.h
        src/GFX3DFunction/Common/d3denumeration.cpp src/GFX3DFunction/Common/d3denumeration.h
        src/GFX3DFunction/Common/d3dsettings.cpp src/GFX3DFunction/Common/d3dsettings.h
        src/GFX3DFunction/Common/d3dutil.cpp src/GFX3DFunction/Common/d3dutil.h
        src/GFX3DFunction/Common/dxutil.cpp src/GFX3DFunction/Common/dxutil.h
        src/GFX3DFunction/RStateMgr.cpp src/GFX3DFunction/RStateMgr.h src/GFX3DFunction/TextureRuntime.h)

add_library(GFX3DFunction STATIC ${SOURCE_FILES})
target_link_libraries(GFX3DFunction GFXMainFrame d3d9)
target_include_directories(GFX3DFunction PUBLIC src/)
