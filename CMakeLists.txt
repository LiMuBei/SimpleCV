cmake_minimum_required (VERSION 2.8)

project (SimpleCV)

set (SimpleCV_VERSION_MAJOR 0)
set (SimpleCV_VERSION_MINOR 1)
set (SimpleCV_VERSION_PATCH 0)

set (CMAKE_DEBUG_POSTFIX _D)

if(WIN32)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREAD ON)
find_package(Boost REQUIRED)
else(WIN32)
find_package(Boost REQUIRED COMPONENTS system filesystem)
endif(WIN32)

find_package(PNG REQUIRED)

configure_file (
	"${PROJECT_SOURCE_DIR}/SimpleCVConfig.h.in"
	"${PROJECT_BINARY_DIR}/SimpleCVConfig.h"
)

add_subdirectory(Core)

install(FILES "README.md" DESTINATION bin)