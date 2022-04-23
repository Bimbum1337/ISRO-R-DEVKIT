include(FindPackageHandleStandardArgs)

# Only look on Windows, there is no DirectX on other platforms
if (WIN32)
    find_path(DirectX_ROOT_DIR Include/d3d9.h PATHS
            "${DirectX_ROOT}"
            "${CMAKE_SOURCE_DIR}/source/third-party/dxsdk"
            "$ENV{DXSDK_DIR}/"
            "$ENV{PROGRAMFILES}/Microsoft DirectX SDK*/"
            REQUIRED)

    set(DirectX_INCLUDE_DIRS ${DirectX_ROOT_DIR}/Include)
    set(DirectX_LIBRARY_PATHS "${DirectX_ROOT_DIR}/Lib")

    find_library(DirectX_D3D9_LIBRARY d3d9 ${DirectX_LIBRARY_PATHS} NO_DEFAULT_PATH)
    find_library(DirectX_D3DX9_LIBRARY d3dx9 ${DirectX_LIBRARY_PATHS} NO_DEFAULT_PATH)
    set(DirectX_LIBRARIES ${DirectX_D3D9_LIBRARY} ${DirectX_D3DX9_LIBRARY})

    find_package_handle_standard_args(DirectX DEFAULT_MSG DirectX_ROOT_DIR DirectX_LIBRARIES DirectX_INCLUDE_DIRS)

else ()
    message(STATUS "Searching for DirectX on this platform is not supported")
endif ()
