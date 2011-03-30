#include "Engine/RenderComponentOpgl2.hpp"
#include "DataHandler/Entity.hpp"

namespace Fenrir {

	RenderComponentOpgl2::RenderComponentOpgl2(Entity* e, DrawEngine* de, int buffers) : RenderComponent(e, de) {
		this->buffers = buffers;



	}

	RenderComponentOpgl2::~RenderComponentOpgl2() {
	}

	void RenderComponentOpgl2::render() {

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, chunkSize, (GLvoid*)VBOoffset);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glDisableClientState(GL_VERTEX_ARRAY);

	}

	void RenderComponentOpgl2::update(GLfloat* buffer) {
		
		unsigned int size;
		GLfloat* eBuffer = e->getBuffer(size, buffers);

		for (int i = 0; i < VBOoffset; i++) {

			buffer[i + VBOoffset] = eBuffer[i];

		}

		delete eBuffer;

		chunkSize = sizeof(GLfloat) * 3 * 2;

	}

	unsigned int RenderComponentOpgl2::getChunkSize() {
		return chunkSize;
	}

}

