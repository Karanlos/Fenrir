#ifndef NODEBASIC_HPP
#define	NODEBASIC_HPP

#include <GL/glew.h>
#include "NodeBase.hpp"

namespace fne {

	class NodeBasic : public NodeBase {
	public:
		NodeBasic(const std::list<NodeBase*>* nodes, GLuint textureID);
		
		void render();
		
	protected:
		GLuint textureID;

	};

}



#endif	/* NODEBASIC_HPP */

