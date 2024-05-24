set(HEADER_FILES
	include/Notreal.h
	src/NotrealApplication.h
	src/Utility.h
	src/NotrealWindow.h
	src/WindowImpl.h
	src/codeGLFW/WindowGLFW.h
	src/Renderer.h
	src/RendererImplement.h
	src/codeOpenGL/RendererOpenGL.h
	src/Shader.h
	src/ShaderImplement.h
	src/codeOpenGL/ShaderOpenGL.h
	src/Image.h
	src/ImageImplement.h
	src/codeOpenGL/ImageOpenGL.h
	src/NotrealEvents.h
	src/NotrealKeys.h
	src/Unit.h
)

set(SOURCE_FILES
	src/NotrealApplication.cpp
	src/NotrealWindow.cpp
	src/codeGLFW/WindowGLFW.cpp
	src/Renderer.cpp
	src/codeOpenGL/RendererOpenGL.cpp
	src/Shader.cpp
	src/codeOpenGL/ShaderOpenGL.cpp
	src/Image.cpp
	src/codeOpenGL/ImageOpenGL.cpp
	src/NotrealEvents.cpp
	src/Unit.cpp
)

add_library(Notreal SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Notreal 
    PUBLIC
        $<$<CONFIG:Debug>:NOTREAL_DEBUG=2>
	$<$<CONFIG:RelWithDebInfo>:NOTREAL_DEBUG=1>
    PRIVATE 
        NOTREAL_LIB
	NOTREAL_GLFW_WINDOW
	NOTREAL_OPENGL
)

if(MSVC)
	target_compile_definitions(Notreal PUBLIC NOTREAL_MS_COMPILER)
endif()

target_include_directories(Notreal PRIVATE ../glfw/include)
target_include_directories(Notreal PRIVATE ../Notreal/src)
target_include_directories(Notreal PRIVATE ../glad/include)
target_include_directories(Notreal PRIVATE ../stbi)

target_precompile_headers(Notreal PRIVATE src/pch.h)

target_link_libraries(Notreal glfw)
target_link_libraries(Notreal glad)
target_link_libraries(Notreal stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Notreal)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug/Notreal)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release/Notreal)