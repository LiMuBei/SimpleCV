# Test
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

	add_test(${testName} ${testName} )
endforeach(testSrc)