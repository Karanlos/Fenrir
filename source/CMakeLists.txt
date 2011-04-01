project(Fenrir)

set(SRC
	main.cpp
	glew.cpp

)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${FENRIR_LIBS})

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${CMAKE_BUILD_DIR}/bin COMPONENT bin
	LIBRARY DESTINATION ${CMAKE_BUILD_DIR}/lib
	ARCHIVE DESTINATION ${CMAKE_BUILD_DIR}/lib/static)
