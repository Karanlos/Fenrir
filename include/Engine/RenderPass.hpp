#ifndef RENDERPASS_H
#define	RENDERPASS_H

#include <list>
#include <GL/glew.h>

#include "Engine/RenderComponent.h"

using namespace std;

namespace Fenrir {

	class Entity;
	class FenrirMath;

	struct PassInfo {
		GLuint FBOID;
		GLuint width;
		GLuint height;
	};

	class RenderPass {

	public:
		RenderPass();
		RenderPass(GLuint width, GLuint height);
		virtual ~RenderPass();

		void init();

		void setActive(bool active);

		void addEntity(Entity* e);
		void removeEntity(Entity* e);

	protected:
		PassInfo* pInfo;
		unsigned int numFBOs;

		list<Entity*> entities;

		bool active;

	};

}

#endif	/* RENDERPASS_H */

