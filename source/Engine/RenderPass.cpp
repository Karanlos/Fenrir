#include "Engine/RenderPass.h"
#include "Engine/RenderComponent.h"

namespace Fenrir {

	RenderPass::RenderPass() {
		active = false;
	}

	RenderPass::RenderPass(GLuint width, GLuint height) {
		active = false;
	}

	RenderPass::~RenderPass() {
	}

	void RenderPass::setActive(bool active) {
		this->active = active;
	}

	void RenderPass::addEntity(Entity* e) {
		entities.push_back(e);
	}

	void RenderPass::removeEntity(Entity* e) {
		entities.remove(e);
	}

}

