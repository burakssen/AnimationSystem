cmake_minimum_required(VERSION 3.21)
project(AnimationSystem)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_DIR src)
set(VENDOR_DIR vendor)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set OpenMP variables manually for macOS
set(OpenMP_ROOT "/opt/homebrew/opt/libomp")
set(OpenMP_CXX_FLAGS "-I${OpenMP_ROOT}/include")
set(OpenMP_CXX_LIB_NAMES "omp")
set(OpenMP_omp_LIBRARY "${OpenMP_ROOT}/lib/libomp.dylib")

# Find OpenMP package
find_package(OpenMP REQUIRED)

add_subdirectory("${VENDOR_DIR}/raylib")
add_subdirectory("${VENDOR_DIR}/entt")
add_subdirectory("${VENDOR_DIR}/spdlog")

file(GLOB_RECURSE SOURCE_FILES
    "${SOURCE_DIR}/**.cpp"
    "${SOURCE_DIR}/**.h"
)

set(INCLUDE_DIRECTORIES
    "${SOURCE_DIR}"
    "${VENDOR_DIR}/raylib/src"
    "${VENDOR_DIR}/entt/src"
    "${VENDOR_DIR}/spdlog/include"
    "${OpenMP_ROOT}/include"  # Add OpenMP include directory
)

add_executable(AnimationSystem ${SOURCE_FILES})

target_include_directories(AnimationSystem PUBLIC ${INCLUDE_DIRECTORIES})

# Link OpenMP
target_link_libraries(AnimationSystem PUBLIC raylib spdlog OpenMP::OpenMP_CXX)

# Add OpenMP compile options
target_compile_options(AnimationSystem PRIVATE ${OpenMP_CXX_FLAGS})

file(COPY "resources" DESTINATION "${CMAKE_BINARY_DIR}")