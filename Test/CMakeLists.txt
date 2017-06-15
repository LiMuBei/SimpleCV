# Test
include_directories (${Boost_INCLUDE_DIRS})

set (CoreTestSources 
	Core/ImageTest.cpp
)

set (IOTestSources
	IO/WriteTest.cpp
)

foreach(testSrc ${CoreTestSources} ${IOTestSources})
	#Extract the filename without an extension (NAME_WE)
	get_filename_component(testName ${testSrc} NAME_WE)

	#Add compile target
	add_executable(${testName} ${testSrc})
	set_target_properties(${testName} PROPERTIES COMPILE_FLAGS "-std=c++11")

	#link to Boost libraries AND your targets and dependencies
	target_link_libraries(${testName} ${Boost_LIBRARIES} Core Io)

	add_test(${testName} ${testName})
	message(STATUS "Added test " ${testName})
endforeach(testSrc)