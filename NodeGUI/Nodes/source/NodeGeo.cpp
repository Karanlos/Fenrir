#include "NodeGeo.hpp"

namespace fne {
	
	NodeGeo::NodeGeo(const std::list<NodeBase*>* nodes) : NodeBase(nodes) {
		
	}
	
	void NodeGeo::render() {
		NodeBase::render();
	}
	
}