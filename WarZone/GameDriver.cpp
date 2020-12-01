#include "Cards.h";
#include "GameEngine.h"
#include "Map.h"
#include "MapLoader.h"
#include "Orders.h"
#include "Player.h"

int main() {
	GameEngine game = GameEngine();
	if (!game.initializeGameValues()) {
		cout << "Could not initialize game" << endl;
		exit(1000);
	}
	game.startupPhase();
}