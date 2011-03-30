#ifndef RENDERCOMPONENTOPGL3_H
#define	RENDERCOMPONENTOPGL3_H

#include "RenderComponent.hpp"

namespace fen {

	class DrawEngine;
	class Entity;

	class RenderComponentOpgl3 : public RenderComponent {

	public:
		RenderComponentOpgl3(Entity* e, DrawEngine* de);
		virtual ~RenderComponentOpgl3();

	protected:

	};

}

#endif	/* RENDERCOMPONENTOPGL3_H */

