set(HEADER_FILES
    include/Notreal.h
    src/NotrealApplication.h
    src/Utility.h
    src/NotrealWindow.h
    src/WindowImpl.h
    src/codeGLFW/WindowGLFW.h
)

set(SOURCE_FILES
    src/NotrealApplication.cpp
    src/NotrealWindow.cpp
    src/codeGLFW/WindowGLFW.cpp
)

add_library(Notreal SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Notreal 
    PUBLIC
        $<$<CONFIG:Debug>:NOTREAL_DEBUG=2>
	$<$<CONFIG:RelWithDebInfo>:NOTREAL_DEBUG=1>
    PRIVATE 
        NOTREAL_LIB
	NOTREAL_GLFW_WINDOW
)

if(MSVC)
	target_compile_definitions(Notreal PUBLIC NOTREAL_MS_COMPILER)
endif()

target_include_directories(Notreal PRIVATE ../glfw/include)
target_include_directories(Notreal PRIVATE ../Notreal)

target_precompile_headers(Notreal PRIVATE src/pch.h)

target_link_libraries(Notreal glfw)