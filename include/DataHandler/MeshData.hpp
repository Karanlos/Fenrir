#ifndef MESHDATA_H
#define	MESHDATA_H

#include <FenrirMath/FenrirMath.h>

using FenrirMath::Vector2Df;
using FenrirMath::Vector3Df;

namespace Fenrir {

	struct Vertex {
		
		Vector3Df position;

	};

	struct UV {

		Vector2Df position;

	};

	struct Face {

		unsigned int verts[3];
		unsigned int uvs[3];

	};

}

#endif	/* MESHDATA_H */

