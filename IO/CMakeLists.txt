# IO
include_directories(${Boost_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

set( IOHeaders
	PNGLoader.h
)

set( IOSources
	PNGLoader.cpp
)

add_library(Io STATIC ${IOHeaders} ${IOSources})

if(WIN32)
set_target_properties(Io PROPERTIES COMPILE_FLAGS "/D_WIN32_WINNT=_WIN32_WINNT_WINXP" VERSION ${SimpleCV_VERSION_STRING} SOVERSION ${SimpleCV_VERSION_STRING})
else(WIN32)
set_target_properties(Io PROPERTIES COMPILE_FLAGS "-fPIC" VERSION ${SimpleCV_VERSION_STRING} SOVERSION ${SimpleCV_VERSION_STRING})
endif(WIN32)

target_link_libraries(Io ${Boost_LIBRARIES} ${PNG_LIBRARIES} Core)

target_include_directories(Io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS Io ARCHIVE DESTINATION lib)