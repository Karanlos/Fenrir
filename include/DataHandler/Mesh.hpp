#ifndef MESH_H
#define	MESH_H

#include <GL/glew.h>

namespace fen {

class Mesh {

	public:
		Mesh();
		virtual ~Mesh();

		GLfloat* getVertexBuffer();
		GLfloat* getNormalBuffer();
		GLfloat* getTangentBuffer();
		GLfloat* getUVBuffer();
		GLuint* getElementBuffer(bool uv);

		GLuint getNumVerticies(bool uv);
		GLuint getNumElements(bool uv);

	private:

	};

}

#endif	/* MESH_H */

