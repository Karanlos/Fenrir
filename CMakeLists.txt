cmake_minimum_required(VERSION 2.8)

project(Fenrir)

include("${CMAKE_SOURCE_DIR}/cmake/config.txt")

if(ISWINDOWS)
	set(FENRIR_LIBS FenrirEngine FenrirDataHandler sfml-main sfml-window-s sfml-graphics-s sfml-system-s)
elseif(ISLINUX)
	set(FENRIR_LIBS FenrirEngine FenrirDataHandler sfml-window-s sfml-graphics-s sfml-system-s)
endif()

set(CMAKE_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/lib/include" "${CMAKE_SOURCE_DIR}/include")

include_directories(${CMAKE_INCLUDE_PATH})

if (ISWINDOWS AND GCCCOMPILER)
	link_directories("${CMAKE_SOURCE_DIR}/lib/mingw")
	set(FENRIR_LIBS ${FENRIR_LIBS} glu32 opengl32)
elseif(MSVC)
	link_directories("${CMAKE_SOURCE_DIR}/lib/msvc")
	set(FENRIR_LIBS ${FENRIR_LIBS} glu32 opengl32)
elseif(ISLINUX)
	link_directories("${CMAKE_SOURCE_DIR}/lib/linux")
	set(FENRIR_LIBS ${FENRIR_LIBS} GLU GL)
endif()

add_definitions(-DSFML_STATIC -DGLEW_STATIC)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(source/Engine)
add_subdirectory(source/DataHandler)
add_subdirectory(source)

