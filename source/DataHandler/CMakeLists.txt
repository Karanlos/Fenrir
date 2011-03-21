project(FenrirDataHandler)

set(SRC
	Entity.cpp
	FileLoader.cpp
	Mesh.cpp

)

add_library(${PROJECT_NAME} STATIC ${SRC})

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)

set(FENRIR_LIBS ${FENRIR_LIBS} ${PROJECT_NAME})