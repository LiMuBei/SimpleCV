# Test
enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

set (CoreTestSources 
	Core/ImageTest.cpp
)

foreach(testSrc ${CoreTestSources})
	#Extract the filename without an extension (NAME_WE)
	get_filename_component(testName ${testSrc} NAME_WE)

	#Add compile target
	add_executable(${testName} ${testSrc})

	#link to Boost libraries AND your targets and dependencies
	target_link_libraries(${testName} ${Boost_LIBRARIES} Core)

	#I like to move testing binaries into a testBin directory
	set_target_properties(${testName} PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/testBin/Core)

	#Finally add it to test execution - 
	#Notice the WORKING_DIRECTORY and COMMAND
	add_test(NAME ${testName} 
			 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin/Core 
			 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testBin/Core/${testName} )
endforeach(testSrc)