cmake_minimum_required(VERSION 3.29)
project(AnimationSystem)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_DIR src)
set(VENDOR_DIR vendor)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("${VENDOR_DIR}/raylib")
add_subdirectory("${VENDOR_DIR}/entt")

file(GLOB_RECURSE SOURCE_FILES 
    "${SOURCE_DIR}/**.cpp" 
    "${SOURCE_DIR}/**.h" 
)

set(INCLUDE_DIRECTORIES
    "${SOURCE_DIR}"
    "${VENDOR_DIR}/raylib/src"
    "${VENDOR_DIR}/entt/src"
)

add_executable(AnimationSystem ${SOURCE_FILES})

target_include_directories(AnimationSystem PUBLIC ${INCLUDE_DIRECTORIES})

target_link_libraries(AnimationSystem PUBLIC raylib)

#file(COPY "resources" DESTINATION "${CMAKE_BINARY_DIR}")
