#ifndef ENTITY_H
#define	ENTITY_H

#include <GL/glew.h>

#include <FenrirMath/FenrirMath.hpp>

#include "Engine/RenderComponent.hpp"
#include "Mesh.hpp"
#include "Enums.hpp"

namespace Fenrir {

	class Entity {

	public:
		Entity();
		virtual ~Entity();

		void setPosition(const fenm::dvec3& vec);
		void move(const fenm::dvec3& vec);

		GLfloat* getBuffer(unsigned int& size, int buffers);
		GLuint* getElementBuffer(unsigned int& size, bool uv);

		void setRenderComponent(RenderComponent* rC);

	protected:
		fenm::dvec3 position;
		Mesh* mesh;
		RenderComponent* rC;

		GLfloat* getVertexBuffer();
		GLfloat* getNormalBuffer();
		GLfloat* getTangentBuffer();
		GLfloat* getUVBuffer();

	};

}

#endif	/* ENTITY_H */

