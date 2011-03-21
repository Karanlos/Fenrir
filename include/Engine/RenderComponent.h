#ifndef RENDERCOMPONENT_H
#define	RENDERCOMPONENT_H

#include <GL/glew.h>

namespace Fenrir {
	
	class DrawEngine;
	class Entity;
	
	class RenderComponent {

	public:
		RenderComponent(Entity* e, DrawEngine* de);
		virtual ~RenderComponent();

		void setVBOOffset(unsigned int offset);

		virtual void render() = 0;
		virtual void update(GLfloat* buffer) = 0;
		void setActive(bool isActive);

	protected:
		GLuint VBOID;
		GLuint VBOoffset;

		bool active;
		
		Entity* e;
		DrawEngine* de;

	};

}

#endif	/* RENDERCOMPONENT_H */

