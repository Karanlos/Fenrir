#ifndef GAMEENGINE_H
#define	GAMEENGINE_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "DataHandler/Enums.hpp"

namespace Fenrir {

	class DrawEngine;

	class GameEngine {

	public:
		GameEngine();
		virtual ~GameEngine();

		void addDrawEngine(DrawEngine* DEngine);
		bool init();

		void run();

	private:
		DrawEngine* DEngine;
		void loadConfigFile();

		int* controlArray;

	};

}

#endif	/* GAMEENGINE_H */

