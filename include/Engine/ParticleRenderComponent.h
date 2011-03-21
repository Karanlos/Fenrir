#ifndef PARTICLERENDERCOMPONENT_H
#define	PARTICLERENDERCOMPONENT_H

#include "RenderComponent.h"

namespace Fenrir {

	class ParticleRenderComponent : public RenderComponent {

	public:
		ParticleRenderComponent(Entity* e, DrawEngine* de);
		virtual ~ParticleRenderComponent();

		void render();
		void update();

	protected:
		void fillBuffer();

	};

}

#endif	/* PARTICLERENDERCOMPONENT_H */

