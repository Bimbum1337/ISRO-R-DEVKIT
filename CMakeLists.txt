project(SRO_DevKit)
cmake_minimum_required(VERSION 3.12)

link_directories(
        $ENV{LIB}
        ${PROJECT_SOURCE_DIR}/source/third-party/dxsdk/Lib
)

include_directories(
        $ENV{INCLUDE}
        ${PROJECT_SOURCE_DIR}/source/third-party/dxsdk/Include
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /X")

# Enforce static linking of the standard library because dynamic linking sucks
set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_RELWITHDEBINFO
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_C_FLAGS_MINSIZEREL
        )
foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

find_package(CxxTest)
if(CXXTEST_FOUND)
    message(STATUS "CxxTest found. Testing enabled!")
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
endif()

message(${CMAKE_CXX_FLAGS})
message(${CMAKE_CXX_FLAGS_DEBUG})
message(${CMAKE_CXX_FLAGS_RELEASE})
message(${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
message(${CMAKE_CXX_FLAGS_MINSIZEREL})

# We are no idiots, ignore these stupid deprecations!
add_compile_definitions(_CRT_SECURE_NO_DEPRECATE _CRT_NON_CONFORMING_SWPRINTFS)

# Set target platform ... to ... Windows XP ... oops
add_definitions(-DWINVER=0x0500)
add_definitions(-D_WIN32_WINNT=0x0500)

include(options.cmake)

# Set loglevel if supplied as parameter
if (DEFINED PUT_LOGLEVEL)
    message(STATUS "Loglevel: ${PUT_LOGLEVEL}")
    add_definitions(-DPUT_LOGLEVEL=${PUT_LOGLEVEL})
endif ()

add_subdirectory(source)
