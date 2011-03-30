#include <fstream>
#include <string>

#include "Engine/DrawEngine.hpp"
#include "Engine/GameEngine.hpp"
#include "DataHandler/FileLoader.hpp"

using namespace std;

namespace Fenrir {

	GameEngine::GameEngine() {
		DEngine = 0;

		controlArray = new int[FCEnum::ARRAY_SIZE];

		loadConfigFile();
	}

	GameEngine::~GameEngine() {

		delete controlArray;

	}

	void GameEngine::addDrawEngine(DrawEngine* DEngine) {

		this->DEngine = DEngine;

	}

	bool GameEngine::init() {

		loadConfigFile();

		DEngine->init();

		return true;

	}

	void GameEngine::run() {

		sf::Event events;
		
		DEngine->run();


		while (DEngine->isOpen()) {
			
			while (DEngine->getEvents(events))
			{
				// Window closed
				if (events.Type == sf::Event::Closed)
					DEngine->close();

				// Escape key pressed
				if ((events.Type == sf::Event::KeyPressed) && (events.Key.Code == sf::Key::Escape))
					DEngine->close();

			}

			DEngine->display();

		}

	}

	void GameEngine::loadConfigFile() {

		//Loads the config that is saved in the config file.
//		FileLoader* configFile = new FileLoader("user.settings", FEnum::controls);
//
//		configFile.useFile();
		controlArray[FCEnum::FORWARD] = sf::Key::W;
		controlArray[FCEnum::BACKWARD] = sf::Key::S;
		controlArray[FCEnum::LEFT] = sf::Key::A;
		controlArray[FCEnum::RIGHT] = sf::Key::D;
		controlArray[FCEnum::JUMP] = sf::Key::Space;
		controlArray[FCEnum::SWING] = sf::Key::F;

	}

}
