project(FenrirEngine)

set(SRC
	DrawEngine.cpp
	GameEngine.cpp
	ParticleRenderComponent.cpp
	RenderComponent.cpp
	RenderComponentOpgl2.cpp
	RenderComponentOpgl3.cpp
	RenderPass.cpp

)

add_library(${PROJECT_NAME} STATIC ${SRC})

install(TARGETS FenrirEngine
	RUNTIME DESTINATION ${CMAKE_BUILD_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_BUILD_DIR}/lib
	ARCHIVE DESTINATION ${CMAKE_BUILD_DIR}/lib/static)
