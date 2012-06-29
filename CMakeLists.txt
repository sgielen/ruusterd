cmake_minimum_required(VERSION 2.8)

project(ruusterd)

include_directories("${PROJECT_BINARY_DIR}")

file(GLOB_RECURSE RUUSTERD_SOURCES src/*.cpp)
add_executable(ruusterd
	${RUUSTERD_SOURCES}
)

add_definitions("-Wall -Wextra -Weffc++ -std=c++0x -pedantic -g3 -O3")

# Set location of our FindFoo.cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")

find_package(rusql REQUIRED)
include_directories(${rusql_INCLUDE_DIRS})
target_link_libraries(ruusterd ${rusql_LIBRARIES})

find_package(Boost COMPONENTS system program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(ruusterd ${Boost_SYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY})
