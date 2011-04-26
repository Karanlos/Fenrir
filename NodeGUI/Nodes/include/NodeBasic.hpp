#ifndef NODEBASIC_HPP

#include <GL/glew.h>
#include "NodeBase.hpp"

namespace fne {

	class NodeBasic : public NodeBase {
	public:
		NodeBasic(GLuint textureID);
		
		void render();
		
	protected:
		GLuint textureID;

	};

}

#define	NODEBASIC_HPP



#endif	/* NODEBASIC_HPP */

