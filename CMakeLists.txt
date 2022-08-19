cmake_minimum_required(VERSION 2.8)
project(DR)

set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)
include(CTest)

find_program(MEMORYCHECK_COMMAND valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "--leak-check=full --show-leak-kinds=all")

if (MSVC)
    # add_compile_options(/W4 /WX)
else()
    # add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Math
if (NOT MSVC)
    set(DR_LINKS m)
else()
    set(DR_LINKS rpcrt4.lib ws2_32.lib)
endif()

if (MSVC)
    add_definitions(-DPDC_NCMOUSE)
    find_library(CURSES pdcurses PATHS "${CMAKE_CURRENT_SOURCE_DIR}/external/lib" NO_DEFAULT_PATH)
else()
    find_package(Curses REQUIRED)
    set(CURSES "${CURSES_CURSES_LIBRARY}")
endif()

if (UNIX AND NOT APPLE)
    find_library(UUID uuid)
    set(DR_LINKS ${DR_LINKS} ${UUID})
endif()

set(Boost_USE_STATIC_LIBS ON)
if (UNIX)
    set(BOOST_ROOT "vendor/unix/boost_1_80_0")
else()
    set(BOOST_ROOT "vendor/win/boost_1_80_0")
endif()
find_package(Boost REQUIRED)
include_directories("${Boost_INCLUDE_DIR}")

# Add links
set(DR_LINKS ${DR_LINKS} ${CURSES} ${JANSSON_LIBRARIES} Boost::boost)

include_directories(include)

if (MSVC)
    include_directories(external/include/pdcurses)
else()
    include_directories("${CURSES_INCLUDE_PATH}")
endif()

# General binary
file(GLOB DR_SOURCE src/*.cpp)

# Static linkage to avoid DLL hell
add_library(DR STATIC ${DR_SOURCE})
if (MSVC)
    target_compile_definitions(DR PRIVATE -DPDC_DLL_BUILD)
endif()
target_link_libraries(DR ${DR_LINKS})

set(DR_LINKS ${DR_LINKS} DR)

# Run all tests in tests directory
file(GLOB files tests/*)
foreach(file ${files})
    get_filename_component(tname ${file} NAME_WLE)
    add_executable(${tname} ${file})
    target_link_libraries(${tname} ${DR_LINKS})
    add_test(NAME ${tname} COMMAND ${tname})
endforeach(file)

add_executable(main main.cpp)
if (MSVC)
    target_compile_definitions(main PRIVATE -DPDC_DLL_BUILD)
endif()
target_link_libraries(main ${DR_LINKS})

add_custom_command(TARGET main POST_BUILD 
               COMMAND ${CMAKE_COMMAND} -E copy_if_different
               "${CMAKE_CURRENT_SOURCE_DIR}/external/lib/pdcurses.dll"              
                $<TARGET_FILE_DIR:main>)
