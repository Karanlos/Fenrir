#include "Engine/GameEngine.hpp"
#include "Engine/DrawEngine.hpp"
#include "DataHandler/Enums.hpp"

int main(int argc, char** argv) {

	Fenrir::GameEngine GEngine;
	Fenrir::DrawEngine* DEngine = new Fenrir::DrawEngine;
	GEngine.addDrawEngine(DEngine);
	GEngine.init();
	GEngine.run();

	delete DEngine;

    return 0;

}

