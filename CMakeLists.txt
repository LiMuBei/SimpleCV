cmake_minimum_required (VERSION 3.0.0)

project (SimpleCV)

set (SimpleCV_VERSION_MAJOR 0)
set (SimpleCV_VERSION_MINOR 1)
set (SimpleCV_VERSION_PATCH 0)

set (CMAKE_DEBUG_POSTFIX _D)

enable_testing()

if(WIN32)
set(Boost_USE_MULTITHREAD ON)
set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
else(WIN32)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
endif(WIN32)

find_package(PNG REQUIRED)

configure_file (
	"${PROJECT_SOURCE_DIR}/SimpleCVConfig.h.in"
	"${PROJECT_BINARY_DIR}/SimpleCVConfig.h"
)

add_subdirectory(Core)
add_subdirectory(Test)

install(FILES "README.md" DESTINATION bin)