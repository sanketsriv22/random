cmake_minimum_required(VERSION 3.16)

# Project name and language
project(Random LANGUAGES CXX C)

# Require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Debug support
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")


# Collect all sources (recursively)
# file(GLOB_RECURSE SOURCES
#     CMAKE_CONFIGURE_DEPENDS
#     ${CMAKE_SOURCE_DIR}/*.cpp
#     # ${CMAKE_SOURCE_DIR}/src/*.cpp
#     # ${CMAKE_SOURCE_DIR}/utils/*.cpp
#     # ${CMAKE_SOURCE_DIR}/external/
# )

file(GLOB_RECURSE SOLUTIONS CMAKE_CONFIGURE_DEPENDS "*.cpp")
foreach(solution ${SOLUTIONS})
    get_filename_component(exe_name ${solution} NAME_WE)
    add_executable(${exe_name} ${solution})

    # Include directories
    target_include_directories(${exe_name} PRIVATE
    # ${CMAKE_SOURCE_DIR}/external
    ${CMAKE_SOURCE_DIR}/utils
)

endforeach()

message(STATUS "Found SOLUTIONS: ${SOLUTIONS}")

# Add executable
# add_executable(random ${SOLUTIONS})



# find_package(glfw3 REQUIRED)
# target_link_libraries(orderbook PRIVATE glfw)

