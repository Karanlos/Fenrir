#include "Engine/GameEngine.hpp"
#include "Engine/DrawEngine.hpp"

int main(int argc, char** argv) {

	fen::GameEngine GEngine;
	fen::DrawEngine* DEngine = new fen::DrawEngine;
	GEngine.addDrawEngine(DEngine);
	GEngine.init();
	GEngine.run();

	delete DEngine;

    return 0;

}

