#ifndef DRAWENGINE_H
#define	DRAWENGINE_H

#include <list>
#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "DataHandler/Structs.hpp"
#include "RenderComponentOpgl2.hpp"

using namespace std;

namespace fen {

	class RenderPass;

	class DrawEngine {

	public:
		DrawEngine();
		virtual ~DrawEngine();

		int init();
		void run();
		void display();
		bool getEvents(sf::Event& events);
		bool isOpen();
		void close();

		void addPass(RenderPass* e);
		void removePass(RenderPass* e);

		void printRenderQueue();

	private:
		DrawEngineInfo DEInfo;
		list<RenderPass*> passes;
		list<GLBufferInfo*> VertexObjects;

		RenderComponent* renderComponent;
		Entity* entityTemp;
		GLBufferInfo* bufferInfoTemp;

		sf::Clock clock;

		void update();
		void loadConfigFile();
		void setWindowDimensions(unsigned int x, unsigned int y, unsigned short BPP);

		virtual void generateGLBuffer(GLBufferInfo* info);
		virtual void updateGLBuffer(GLBufferInfo* info);
		virtual void deleteGLBuffer(GLBufferInfo* info);

	};

}

#endif	/* DRAWENGINE_H */

