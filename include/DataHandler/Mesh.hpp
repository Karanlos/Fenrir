#ifndef MESH_H
#define	MESH_H

#include <vector>
#include <fstream>

#include <GL/glew.h>

namespace fen {

	struct Vertex;
	struct Face;

	class Mesh {
	public:
		/**
		 * Default constructor.
		 * @param fileName: The name of the file that contains the mesh data.
		 */
		Mesh(const char* fileName);
		virtual ~Mesh();

		/**
		 * Returns the vertexbuffer of the mesh.
		 * @return Returns a pointer to an array that holds the vertex data.
		 */
		GLfloat* getVertexBuffer();
		/**
		 * Returns the vertexbuffer of the mesh.
		 * @return Returns a pointer to an array that holds the vertex data.
		 */
		GLfloat* getUVBuffer();
		GLuint* getElementBuffer(bool uv);

		GLuint getNumVerticies(bool uv);
		GLuint getNumElements(bool uv);

	protected:
		/**
		 * Loads the mesh information and stores it.
		 * @param fileName: Name of the file that containts the Mesh
		 */
		void loadMeshFile(const char* fileName);

		std::vector<Vertex> vertexVector;
		//			std::vector UVVector;
		std::vector<Face> faceVector;
		//			std::vector elementUVVecter;

	};

}

#endif	/* MESH_H */

