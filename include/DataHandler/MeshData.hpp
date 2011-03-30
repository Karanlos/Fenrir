#ifndef MESHDATA_H
#define	MESHDATA_H

#include <FenrirMath/FenrirMath.hpp>

namespace fen {

	struct Vertex {
		
		fenm::vec3 position;

	};

	struct UV {

		fenm::vec2 position;

	};

	struct Face {

		unsigned int verts[3];
		unsigned int uvs[3];

	};

}

#endif	/* MESHDATA_H */

