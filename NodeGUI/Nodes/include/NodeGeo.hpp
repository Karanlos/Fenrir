#ifndef NODEGEO_H
#define NODEGEO_H

#include <GL/glew.h>
#include "NodeBase.hpp"

namespace fne {

	class NodeGeo : public NodeBase {
	public:
		
		NodeGeo(const std::list<NodeBase*>* nodes);

		void render();
		
	protected:

		GLuint geoID;

	};

}

#endif //NODEGEO_H