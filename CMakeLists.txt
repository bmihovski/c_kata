cmake_minimum_required(VERSION 3.31)
project(kata_machine C)

set(CMAKE_C_STANDARD 23)
# osx specific
set(CMAKE_MACOSX_RPATH TRUE)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add source files
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_library(kata_machine STATIC ${SRC_FILES})

# Include directories
target_include_directories(kata_machine PUBLIC src)

# Find cmocka using pkg-config (more reliable with brew installations)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CMOCKA REQUIRED cmocka)
# Add error checking for cmocka
if(NOT CMOCKA_FOUND)
    message(FATAL_ERROR "cmocka not found. Please install it: brew install cmocka")
endif()

# Add tests
file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.c")
foreach(test_file IN LISTS TEST_FILES)
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} PRIVATE kata_machine ${CMOCKA_LIBRARIES})
    target_include_directories(${test_name} PRIVATE ${CMOCKA_INCLUDE_DIRS})
    target_link_directories(${test_name} PRIVATE ${CMOCKA_LIBRARY_DIRS})
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

enable_testing()
