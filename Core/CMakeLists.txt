# Core
include_directories(${Boost_INCLUDE_DIR})

set( CoreHeaders
	Image.h
)

set( CoreSources
	Image.cpp
)

add_library(Core STATIC ${CoreHeaders} ${CoreSources})

if(WIN32)
set_target_properties(Core PROPERTIES COMPILE_FLAGS "/D_WIN32_WINNT=_WIN32_WINNT_WINXP")
else(WIN32)
set_target_properties(Core PROPERTIES COMPILE_FLAGS "-fPIC")
endif(WIN32)

target_link_libraries(Core ${Boost_LIBRARIES} ${PNG_LIBRARIES})

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS Core ARCHIVE DESTINATION lib)