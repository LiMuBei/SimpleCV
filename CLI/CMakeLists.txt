# CLI
set( CLIHeaders
	SimpleCVConfig.h
)

set( CLISources
	main.cpp
)

add_executable (CLI ${CLIHeaders} ${CLISources})

if(WIN32)
set_target_properties(CLI PROPERTIES COMPILE_FLAGS "/D_WIN32_WINNT=_WIN32_WINNT_WINXP" VERSION ${SimpleCV_VERSION_STRING} RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
else(WIN32)
set_target_properties(CLI PROPERTIES COMPILE_FLAGS "-fPIC" VERSION ${SimpleCV_VERSION_STRING} RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif(WIN32)

target_link_libraries(CLI ${Boost_LIBRARIES} ${PNG_LIBRARIES} Core Io)

target_include_directories(CLI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIR} ${PNG_INCLUDE_DIR})

install(TARGETS CLI RUNTIME DESTINATION bin)