#include "Cards.h"
#include "GameEngine.h"

int main() {
	GameEngine game = GameEngine();
	if (!game.initializeGameValues()) {
		cout << "Could not initialize game" << endl;
		exit(1000);
	}
	game.startupPhase();
	cout << endl;
	cout << "=========================================" << endl;
	cout << "The game has been initialized. Game Start" << endl;
	cout << "=========================================" << endl;
	cout << endl;
	//call the main game loop after intiatng the startup phase.
	game.mainGameLoop();
}
