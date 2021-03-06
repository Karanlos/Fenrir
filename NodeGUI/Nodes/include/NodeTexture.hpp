#ifndef NODEGEO_H
#define NODEGEO_H

#include <GL/glew.h>
#include "NodeBase.hpp"

namespace fne {
	
	class NodeTexture : public NodeBase {
	public:
		
		void render();
		
	protected:
		GLuint textureID;
		
	};
	
}

#endif //NODEGEO_H