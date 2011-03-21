#include "Engine/GameEngine.h"
#include "Engine/DrawEngine.h"
#include "DataHandler/Enums.h"

int main(int argc, char** argv) {

	Fenrir::GameEngine GEngine;
	Fenrir::DrawEngine* DEngine = new Fenrir::DrawEngine;
	GEngine.addDrawEngine(DEngine);
	GEngine.init();
	GEngine.run();

	delete DEngine;

    return 0;

}

