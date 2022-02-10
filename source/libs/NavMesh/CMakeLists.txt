set(SOURCE_FILES src/RTNavMeshTerrain.cpp)

add_library(NavMesh STATIC ${SOURCE_FILES})
target_include_directories(NavMesh
        PUBLIC
        include/
        ${DirectX_INCLUDE_DIRS}
        PRIVATE include/NavMesh)

target_link_libraries(NavMesh ${DirectX_LIBRARIES})
target_link_directories(NavMesh PUBLIC ${DirectX_LIBRARY_PATHS})
