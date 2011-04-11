#include <cstdlib>

#include "Engine/DrawEngine.hpp"
#include "Engine/RenderPass.hpp"
#include "DataHandler/Entity.hpp"
#include "DataHandler/Mesh.hpp"
#include "DataHandler/Enums.hpp"

namespace fen {

	DrawEngine::DrawEngine() {
		entityTemp = new Entity();
		renderComponent = new RenderComponentOpgl2(entityTemp, this, FBEnum::VNTUV_BUFFER);
		bufferInfoTemp = new GLBufferInfo;
		bufferInfoTemp->VAOID = 0;
		bufferInfoTemp->VBOID = 0;
		bufferInfoTemp->EBOID = 0;
	}

	DrawEngine::~DrawEngine() {
		delete entityTemp;
	}

	int DrawEngine::init() {

		loadConfigFile();

		DEInfo.cSettings.MajorVersion = 2;
		DEInfo.cSettings.MinorVersion = 1;
		DEInfo.cSettings.DepthBits = 24;
		DEInfo.cSettings.AntialiasingLevel = 0;
		DEInfo.cSettings.StencilBits = 8;
		glEnable(GL_DEPTH_TEST);

		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClearDepth(1.0f);
		glDepthFunc(GL_LEQUAL);

		glDepthMask(GL_TRUE);

		return 0;
		
	}

	void DrawEngine::run() {

		DEInfo.window.Create(DEInfo.vMode, "OpenGL Test", sf::Style::Close, DEInfo.cSettings);

		glewExperimental = true;
		GLenum glewErr = glewInit();

		if(GLEW_OK != glewErr) {
			cout << "GLEW error: " << glewGetErrorString(glewErr) << endl;
		}
		cout << "OpenGL " << glGetString(GL_VERSION) << endl;

		GLBufferInfo* info = new GLBufferInfo;

		generateGLBuffer(info);
		cout << "VAOID: " << info->VAOID << "  VBOID: " << info->VBOID << "  EBOID: " << info->EBOID << endl;
		deleteGLBuffer(info);
		
	}

	void DrawEngine::display() {
		if(isOpen()) {

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0, (float)1 / (float)1, 1.0, 200.0);
			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(20, 20, 20, 0, 0, 0, 0, 0, 1);
			glRotatef(clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
			glRotatef(clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
			glRotatef(clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);

			if(bufferInfoTemp->VBOID == 0)
				generateGLBuffer(bufferInfoTemp);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			updateGLBuffer(bufferInfoTemp);

			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferInfoTemp->VBOID);
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, bufferInfoTemp->EBOID);

			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, (3 + 3) * sizeof(GLfloat), 0);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			glDisableClientState(GL_VERTEX_ARRAY);

			glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

			DEInfo.window.Display();
		}
	}

	bool DrawEngine::getEvents(sf::Event& events) {
		return DEInfo.window.GetEvent(events);
	}

	bool DrawEngine::isOpen() {
		return DEInfo.window.IsOpened();
	}

	void DrawEngine::close() {
		DEInfo.window.Close();
	}

	void DrawEngine::addPass(RenderPass* e) {
		passes.push_back(e);
	}

	void DrawEngine::removePass(RenderPass* e) {
		passes.remove(e);
	}

	void DrawEngine::printRenderQueue() {

		for(list<RenderPass*>::iterator i = passes.begin(); i != passes.end(); i++)
			cout << &(*i) << endl;

		cout << "\n" << endl;

	}

	void DrawEngine::loadConfigFile() {
		setWindowDimensions(640, 480, 32);
	}

	void DrawEngine::setWindowDimensions(unsigned int x, unsigned int y, unsigned short bpp) {
		DEInfo.vMode.Width = x;
		DEInfo.vMode.Height = y;
		DEInfo.vMode.BitsPerPixel = bpp;
	}

	void DrawEngine::generateGLBuffer(GLBufferInfo* info) {

		if(DEInfo.cSettings.MajorVersion == 2) {

			glGenBuffersARB(2, &(info->VBOID));
			info->VAOID = 0;

		} else {
			
			glGenVertexArrays(1, &(info->VAOID));
			glGenBuffers(2, &(info->VBOID));

		}

	}

	void DrawEngine::updateGLBuffer(GLBufferInfo* info) {

		unsigned int sizeV, sizeE;

		GLfloat* vBuffer = entityTemp->getBuffer(sizeV, 0);
		GLuint* eBuffer = entityTemp->getElementBuffer(sizeE, false);

		glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferInfoTemp->VBOID);
		glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(GLfloat) * 4 * 3 * 3, vBuffer, GL_STATIC_DRAW_ARB);
		glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);

		glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, bufferInfoTemp->EBOID);
		glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(GLuint) * 6, eBuffer, GL_STATIC_DRAW_ARB);
		glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

		delete vBuffer, eBuffer;
		
	}

	void DrawEngine::deleteGLBuffer(GLBufferInfo* info) {

		if(DEInfo.cSettings.MajorVersion == 2) {

			glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

			glDeleteBuffersARB(2, &(info->VBOID));

		} else {

			glBindVertexArray(info->VAOID);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			glBindVertexArray(0);

			glDeleteBuffers(2, &(info->VBOID));
			glDeleteVertexArrays(1, &info->VAOID);

		}

	}
	
}
