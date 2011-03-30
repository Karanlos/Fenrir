#ifndef RENDERCOMPONENTOPGL2_H
#define	RENDERCOMPONENTOPGL2_H

#include "RenderComponent.hpp"

namespace Fenrir {

	class RenderComponentOpgl2 : public RenderComponent {

	public:
		RenderComponentOpgl2(Entity* e, DrawEngine* de, int buffers);
		virtual ~RenderComponentOpgl2();

		void render();
		void update(GLfloat* buffer);

		unsigned int getChunkSize();

	protected:
		unsigned int chunkSize;
		int buffers;

	};

}

#endif	/* RENDERCOMPONENTOPGL2_H */

