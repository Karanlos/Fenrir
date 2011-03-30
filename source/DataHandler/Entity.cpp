#include "DataHandler/Entity.hpp"
#include "DataHandler/Mesh.hpp"

using namespace std;

namespace Fenrir {

	Entity::Entity() {
		mesh = new Mesh();
		rC  = 0;
	}

	Entity::~Entity() {
		delete mesh;

		if(rC != 0)
			delete rC;

	}

	void Entity::setPosition(const fenm::dvec3& vec) {
		position = vec;
	}

	void Entity::move(const fenm::dvec3& vec) {
		position += vec;
	}

	// Returns a pointer to a buffer that contains the transformed vertex(and normal and/or uv) information or returns an element buffer.
	// The parameter size will contain the byte size of the buffer.
	GLfloat* Entity::getBuffer(unsigned int& size, int buffers) {

		GLfloat* tempBuffer;
		GLfloat* vertexTempBuffer = mesh->getVertexBuffer();
		GLfloat* normalTempBuffer = mesh->getNormalBuffer();

		tempBuffer = new GLfloat[24];

		size = mesh->getNumVerticies(false) * (3 + 3) * sizeof(GLfloat);

		for(int i = 0; i < mesh->getNumVerticies(false); i++) {
			// Vertex Position
			tempBuffer[6 * i]     = vertexTempBuffer[3 * i];
			tempBuffer[6 * i + 1] = vertexTempBuffer[3 * i + 1];
			tempBuffer[6 * i + 2] = vertexTempBuffer[3 * i + 2];

			// Normal
			tempBuffer[6 * i + 3] = normalTempBuffer[3 * i];
			tempBuffer[6 * i + 4] = normalTempBuffer[3 * i + 1];
			tempBuffer[6 * i + 5] = normalTempBuffer[3 * i + 2];
		}

		delete vertexTempBuffer, normalTempBuffer;

		return tempBuffer;

	}

	GLuint* Entity::getElementBuffer(unsigned int& size, bool uv) {

		GLuint* tempBuffer = mesh->getElementBuffer(false);

		size = mesh->getNumElements(false) * sizeof(GLuint);

		return tempBuffer;

	}

	void Entity::setRenderComponent(RenderComponent* rC) {
		this->rC = rC;
	}

}

