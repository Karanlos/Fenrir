cmake_minimum_required(VERSION 2.8)

project(FenrirNodes)

include("${CMAKE_SOURCE_DIR}/../cmake/macros.txt")
include("${CMAKE_SOURCE_DIR}/../cmake/config.txt")

option(IS64BIT "Option to toggle to which system to libraries should be build" OFF)

if(ISWINDOWS)
	set(FENRIR_LIBS)
elseif(ISLINUX)
	set(FENRIR_LIBS)
endif()

if(IS64BIT)
	set(IS64 "64")
else()
	set(IS64 "32")
endif()

set(CMAKE_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../lib${IS64}/include" "${CMAKE_SOURCE_DIR}/Nodes/include")

include_directories(${CMAKE_INCLUDE_PATH})

if (ISWINDOWS AND GCCCOMPILER)
	link_directories("${CMAKE_SOURCE_DIR}/lib${IS64}/mingw")
	set(FENRIR_LIBS ${FENRIR_LIBS} glu32 opengl32)
elseif(MSVC)
	link_directories("${CMAKE_SOURCE_DIR}/lib${IS64}/msvc")
	set(FENRIR_LIBS ${FENRIR_LIBS} glu32 opengl32)
elseif(ISLINUX)
	link_directories("${CMAKE_SOURCE_DIR}/../lib${IS64}/linux")
	set(FENRIR_LIBS ${FENRIR_LIBS} GLU)
endif()

add_definitions(-DGLEW_STATIC)

set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib${IS64}")

add_subdirectory(Nodes/source)

