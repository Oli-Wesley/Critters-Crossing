#include "GameScene.h"

#include "../Libraries/GameEngine/Systems/PrefabRegistry.h"
#include "../Libraries/GameEngine/Components.h"
#include "../Scripts/S_Passport.h"
#include "../Scripts/S_Stamp.h"
#include "../Scripts/S_GameSceneManager.h"


void GameScene::load() {
	{
		// set background colour
		scene_background_color = sf::Color(69, 40, 40);
		S_GameSceneManager* s_gameSceneScript = scene_root->addScript<S_GameSceneManager>();

		// load objects from prefab, add them as a child to the scene root, and save their reference 
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* character_creator = scene_root->addChild(pref->InstantiatePrefab("P_CharacterCreator", 25, 25));

		GameObject* passport = scene_root->addChild(pref->InstantiatePrefab("P_Passport", 305, 150));

		GameObject* green_stamp = scene_root->addChild(pref->InstantiatePrefab("P_Stamp", "stamp_green", 605, 325));
		GameObject* red_stamp = scene_root->addChild(pref->InstantiatePrefab("P_Stamp", "stamp_red", 605, 425));
		GameObject* stamp_tray = scene_root->addChild(pref->InstantiatePrefab("P_RenderableObject", 590, 310));
		scene_root->addChild(pref->InstantiatePrefab("P_CharacterFrame")); // doesnt need to be saved as unused anywhere else.
		GameObject* lamp_manager = scene_root->addChild(pref->InstantiatePrefab("P_LampManager", 665, 125));
		GameObject* desk = scene_root->addChild(pref->InstantiatePrefab("P_Desk", 10, 385));

		scene_root->addChild(pref->InstantiatePrefab("P_ElFisho", 718.75, 35));

		red_stamp->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Stamp_red.png");

		// give stamp script reference to the passport so it can be stamped.
		green_stamp->getComponent<S_Stamp>()->givePassportScript(passport->getComponent<S_Passport>());
		red_stamp->getComponent<S_Stamp>()->givePassportScript(passport->getComponent<S_Passport>());


		// stamp tray was just a renderable object, so it needs to be setup here. (I cba to make it a prefab)
		stamp_tray->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/StampTray.png");
		stamp_tray->getTransform()->setLocalScale(5);
		stamp_tray->getTransform()->setLocalZheight(6);

		// setup the passport.
		s_gameSceneScript->setupPassport();
	}
}
