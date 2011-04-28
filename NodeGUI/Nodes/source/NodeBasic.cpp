#include "NodeBasic.hpp"

namespace fne {
	
	NodeBasic::NodeBasic(const std::list<NodeBase*>* nodes, GLuint textureID) : NodeBase(nodes) {
		
		this->textureID = textureID;
		
	}
	
	void NodeBasic::render() {
		NodeBase::render();
	}
	
}
