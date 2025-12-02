#include "Libraries/GameEngine.h"
#include "Scenes/GameScene.h"
#include "Scenes/TitleScene.h"
#include "Scenes/GameOverScene.h"
#include "Libraries/GameEngine/Components.h"
#include "Libraries/GameEngine/Systems/PrefabRegistry.h"
#include "Prefabs/PrefabLoader.h" // need to include as this registers all the prefabs.

int main() {
	srand(time(0)); // setup random numbers
	// Add Scenes
	GameSystem* sys = GameSystem::get();
	sys->addScene(new GameScene, "GameScene"); 
	sys->addScene(new TitleScene, "TitleScene");
	sys->addScene(new GameOverScene, "GameOverScene");
	// set window settings (not needed, there are default values)
	sys->setFramerate(120);
	sys->setTitle("Critters Crossing");
	sys->setResolution(960, 540);
	sys->setDebug(0); // debug 

	// start game (anything after this in main will not be called untill the game is stopped).
	sys->start("TitleScene");

	return 0;
}