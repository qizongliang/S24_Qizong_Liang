set(HEADER_FILES
    include/Notreal.h
    src/NotrealApplication.h
    src/Utility.h
)

set(SOURCE_FILES
    src/NotrealApplication.cpp
)

add_library(Notreal SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Notreal 
    PUBLIC
        $<$<CONFIG:Debug>:NOTREAL_DEBUG=2>
	$<$<CONFIG:RelWithDebInfo>:NOTREAL_DEBUG=1>
    PRIVATE 
        NOTREAL_LIB
)

if(MSVC)
	target_compile_definitions(Notreal PUBLIC NOTREAL_MS_COMPILER)
endif()

target_precompile_headers(Notreal PRIVATE src/pch.h)