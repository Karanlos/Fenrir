project(FenrirDataHandler)

set(SRC
	Entity.cpp
	FileLoader.cpp
	Mesh.cpp

)

add_library(${PROJECT_NAME} STATIC ${SRC})

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${CMAKE_BUILD_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_BUILD_DIR}/lib
	ARCHIVE DESTINATION ${CMAKE_BUILD_DIR}/lib/static)