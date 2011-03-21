#ifndef ENTITY_H
#define	ENTITY_H

#include <GL/glew.h>

#include <FenrirMath/FenrirMath.h>

#include "Engine/RenderComponent.h"
#include "Mesh.h"
#include "Enums.h"

using FenrirMath::Vector3Df;

namespace Fenrir {

	class Entity {

	public:
		Entity();
		virtual ~Entity();

		void setPosition(Vector3Df vec);
		void move(Vector3Df vec);

		GLfloat* getBuffer(unsigned int& size, int buffers);
		GLuint* getElementBuffer(unsigned int& size, bool uv);

		void setRenderComponent(RenderComponent* rC);

	protected:
		Vector3Df position;
		Mesh* mesh;
		RenderComponent* rC;

		GLfloat* getVertexBuffer();
		GLfloat* getNormalBuffer();
		GLfloat* getTangentBuffer();
		GLfloat* getUVBuffer();

	};

}

#endif	/* ENTITY_H */

