cmake_minimum_required(VERSION 2.8)

project(Fenrir)

macro(configure_files srcDir destDir)
    make_directory(${destDir})

    file(GLOB templateFiles RELATIVE ${srcDir} ${srcDir}/*)
    foreach(templateFile ${templateFiles})
        set(srcTemplatePath ${srcDir}/${templateFile})
        if(NOT IS_DIRECTORY ${srcTemplatePath})
            configure_file(
                    ${srcTemplatePath}
                    ${destDir}/${templateFile}
                    @ONLY)
        endif(NOT IS_DIRECTORY ${srcTemplatePath})
    endforeach(templateFile)
endmacro(configure_files)

include("${CMAKE_SOURCE_DIR}/cmake/config.txt")

option(IS64BIT "Option to toggle to which system to libraries should be build" OFF)

if(ISWINDOWS)
	set(FENRIR_LIBS FenrirEngine FenrirDataHandler sfml-main sfml-window-s sfml-graphics-s sfml-system-s)
elseif(ISLINUX)
	set(FENRIR_LIBS FenrirEngine FenrirDataHandler sfml-window sfml-graphics sfml-system)
endif()

if(IS64BIT)
	set(IS64 "64")
else()
	set(IS64 "32")
endif()

set(CMAKE_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/lib${IS64}/include" "${CMAKE_SOURCE_DIR}/include")

include_directories(${CMAKE_INCLUDE_PATH})

if (ISWINDOWS AND GCCCOMPILER)
	link_directories("${CMAKE_SOURCE_DIR}/lib${IS64}/mingw")
	set(FENRIR_LIBS ${FENRIR_LIBS} glu32 opengl32)
elseif(MSVC)
	link_directories("${CMAKE_SOURCE_DIR}/lib${IS64}/msvc")
	set(FENRIR_LIBS ${FENRIR_LIBS} glu32 opengl32)
elseif(ISLINUX)
	link_directories("${CMAKE_SOURCE_DIR}/lib${IS64}/linux" "${CMAKE_SOURCE_DIR}/lib${IS64}/linux/dll")
	set(FENRIR_LIBS ${FENRIR_LIBS} GLU)
	configure_files("${CMAKE_SOURCE_DIR}/lib${IS64}/linux/dll" "${CMAKE_BINARY_DIR}/bin${IS64}")
endif()

add_definitions(-DSFML_STATIC -DGLEW_STATIC)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib${IS64}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin${IS64}")

add_subdirectory(source/Engine)
add_subdirectory(source/DataHandler)
add_subdirectory(source)

