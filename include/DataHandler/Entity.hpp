#ifndef ENTITY_H
#define	ENTITY_H

#include <GL/glew.h>

#include <FenrirMath/FenrirMath.hpp>

#include "Engine/RenderComponent.hpp"
#include "Enums.hpp"

namespace fen {
	
	class Mesh;

	class Entity {
	public:
		Entity();
		virtual ~Entity();

		void setPosition(const fenm::dvec3& vec);
		void move(const fenm::dvec3& vec);

		/**
		 * @param size: Reference to an unsigned int that stores the total byte size of the buffer.
		 * @return Returns a pointer to a buffer that contains the transformed vertex(and normal and/or uv) information or returns an element buffer.
		 */
		GLfloat* getBuffer(unsigned int& size, int buffers);
		GLuint* getElementBuffer(unsigned int& size, bool uv);

		void setRenderComponent(RenderComponent* rC);

	protected:
		fenm::dvec3 position;
		Mesh* mesh;
		RenderComponent* rC;

		GLfloat* getVertexBuffer();
		/**
		 *
		 * @return
		 */
		GLfloat* getNormalBuffer();
		GLfloat* getTangentBuffer();
		GLfloat* getUVBuffer();

	};

}

#endif	/* ENTITY_H */

