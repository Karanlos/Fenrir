#ifndef ENUMS_H
#define	ENUMS_H

namespace Fenrir {
	
	namespace FBEnum {
		enum Buffers {
			VERTEX_BUFFER = 1 << 0,
			NORMAL_BUFFER = 1 << 1,
			TANGENT_BUFFER = 1 << 2,
			UV_BUFFER = 1 << 3,
			VNTUV_BUFFER = VERTEX_BUFFER + NORMAL_BUFFER + TANGENT_BUFFER + UV_BUFFER
		};
	}

	namespace FCEnum {
		enum Controls {
			FORWARD,
			BACKWARD,
			LEFT,
			RIGHT,
			JUMP,
			SWING,
			ARRAY_SIZE
		};
	}

}

#endif	/* ENUMS_H */

