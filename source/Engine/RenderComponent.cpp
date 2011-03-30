#include "Engine/RenderComponent.hpp"

namespace Fenrir {

	RenderComponent::RenderComponent(Entity* e, DrawEngine* de) {
		this->e = e;
		this->de = de;

		active = false;
	}

	RenderComponent::~RenderComponent() {
	}

	void RenderComponent::setVBOOffset(unsigned int offset) {
		VBOoffset = offset;
	}

	void RenderComponent::setActive(bool isActive) {
		active = isActive;
	}

}

