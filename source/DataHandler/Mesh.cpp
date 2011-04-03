#include "DataHandler/Mesh.hpp"
#include "DataHandler/MeshData.hpp"

using std::vector;

namespace fen {

	Mesh::Mesh(const char* fileName) {
		loadMeshFile(fileName);

		for(vector<Vertex>::iterator iter = vertexVector.begin(); iter != vertexVector.end(); iter++)
			std::cout << (*iter).position.x() << " " << (*iter).position.y() << " " << (*iter).position.z() << std::endl;

	}

	Mesh::~Mesh() {
	}

	GLfloat* Mesh::getVertexBuffer() {

		GLfloat* tempBuffer = new GLfloat[vertexVector.size() * 3];

		for(unsigned int i = 0; i < vertexVector.size(); i++) {
			std::cout << "Hej" << std::endl;
			tempBuffer[i * 3]	  = vertexVector[i].position.x();
			tempBuffer[i * 3 + 1] = vertexVector[i].position.y();
			tempBuffer[i * 3 + 2] = vertexVector[i].position.z();
		}

		return tempBuffer;

	}

	GLfloat* Mesh::getNormalBuffer() {

		GLfloat* tempBuffer = new GLfloat[vertexVector.size() * 3];

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

	void Mesh::loadMeshFile(const char* fileName) {

		Vertex v1;
		Vertex v2;
		Vertex v3;
		Vertex v4;
		vertexVector.reserve(4);
		v1.position.setPosition(1.0f,1.0f,0.0f);
		v2.position.setPosition(1.0f,-1.0f,0.0f);
		v3.position.setPosition(-1.0f,-1.0f,0.0f);
		v4.position.setPosition(-1.0f,1.0f,0.0f);
		vertexVector.push_back(v1);
		vertexVector.push_back(v2);
		vertexVector.push_back(v3);
		vertexVector.push_back(v4);

		Face f1;
		Face f2;
		
		f1.verts[0] = 0;
		f1.verts[1] = 1;
		f1.verts[2] = 2;
		
		f2.verts[0] = 0;
		f2.verts[1] = 2;
		f2.verts[2] = 3;
		
		faceVector.push_back(f1);
		faceVector.push_back(f2);

		faceVector.resize(2, f1);

	}

}
