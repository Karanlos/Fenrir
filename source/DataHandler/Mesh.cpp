#include "DataHandler/Mesh.h"

namespace Fenrir {

	Mesh::Mesh() {
	}

	Mesh::~Mesh() {
	}

	GLfloat* Mesh::getVertexBuffer() {

		GLfloat* tempBuffer = new GLfloat[4 * 3];

		tempBuffer[0]  = 1.0f;
		tempBuffer[1]  = 1.0f;
		tempBuffer[2]  = 0.0f;
		
		tempBuffer[3]  = 1.0f;
		tempBuffer[4]  = -1.0f;
		tempBuffer[5]  = 0.0f;

		tempBuffer[6]  = -1.0f;
		tempBuffer[7]  = -1.0f;
		tempBuffer[8]  = 0.0f;

		tempBuffer[9]  = -1.0f;
		tempBuffer[10] = 1.0f;
		tempBuffer[11] = 0.0f;

		return tempBuffer;

	}

	GLfloat* Mesh::getNormalBuffer() {

		GLfloat* tempBuffer = new GLfloat[4 * 3];

		tempBuffer[0]  = 0.0f;
		tempBuffer[1]  = 0.0f;
		tempBuffer[2]  = 1.0f;

		tempBuffer[3]  = 0.0f;
		tempBuffer[4]  = 0.0f;
		tempBuffer[5]  = 1.0f;

		tempBuffer[6]  = 0.0f;
		tempBuffer[7]  = 0.0f;
		tempBuffer[8]  = 1.0f;

		tempBuffer[9]  = 0.0f;
		tempBuffer[10] = 0.0f;
		tempBuffer[11] = 1.0f;

		return tempBuffer;


	}

	GLfloat* Mesh::getTangentBuffer() {
		return 0;
	}

	GLfloat* Mesh::getUVBuffer() {
		return 0;
	}

	GLuint* Mesh::getElementBuffer(bool uv) {
		GLuint* tempBuffer = new GLuint[6];

		tempBuffer[0] = 0;
		tempBuffer[1] = 1;
		tempBuffer[2] = 2;
		tempBuffer[3] = 0;
		tempBuffer[4] = 2;
		tempBuffer[5] = 3;

		return tempBuffer;
	}

	GLuint Mesh::getNumVerticies(bool uv) {
		return 4;
	}

	GLuint Mesh::getNumElements(bool uv) {
		return 6;
	}

}
