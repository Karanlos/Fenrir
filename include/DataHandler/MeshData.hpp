#ifndef MESHDATA_H
#define	MESHDATA_H

#include <FenrirMath/FenrirMath.hpp>

namespace fen {

	struct Vertex {
		/**
		 A 3D vector that represents the position of the vertex.
		 */
		fenm::vec3 position;
		/**
		 Number of faces connected to the vertex.
		 */
		char numFaces;

	};

	struct UV {
		/**
		 A 2D vector that represents the position.
		 */
		fenm::vec2 position;

	};

	struct Face {
		/**
		 Array holding 3 indicies og the verts the face is made of.
		 */
		unsigned int verts[3];
		/**
		 Array holding 3 indicies to the UV's that the face is mapped to.
		 */
		unsigned int uvs[3];

	};

}

#endif	/* MESHDATA_H */

