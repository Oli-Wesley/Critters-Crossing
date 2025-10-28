#pragma once

#include "Scripts/S_CharactorCreator.h"
#include "Scripts/S_AcceptDeny.h"
#include "Scripts/S_Passport.h"
#include "Scripts/S_Stamp.h"
#include "Scripts/S_GameSceneManager.h"

class GameScene : public Scene {
public:
	void load() override {
		// set background colour
		scene_background_color = sf::Color(69, 40, 40);
		S_GameSceneManager* s_gameSceneScript = scene_root->addScript<S_GameSceneManager>();

		// load objects from prefab, add them as a child to the scene root, and save their reference 
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* character_creator = scene_root->addChild(pref->InstantiatePrefab("P_CharacterCreator", 25, 25));

		GameObject* passport = scene_root->addChild(pref->InstantiatePrefab("P_Passport", 310, 160));

		GameObject* green_stamp = scene_root->addChild(pref->InstantiatePrefab("P_Stamp", "stamp_green", 650, 265));
		GameObject* red_stamp = scene_root->addChild(pref->InstantiatePrefab("P_Stamp", "stamp_red", 650, 370));
		GameObject* stamp_tray = scene_root->addChild(pref->InstantiatePrefab("P_RenderableObject", 635, 250));
		GameObject* next_button = scene_root->addChild(pref->InstantiatePrefab("P_RenderableObject", "Next_Button", 25, 400));
		scene_root->addChild(pref->InstantiatePrefab("P_CharacterFrame")); // doesnt need to be saved as unused anywhere else.

		red_stamp->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Stamp_red.png");

		// give stamp script reference to the passport so it can be stamped.
		green_stamp->getComponent<S_Stamp>()->givePassportScript(passport->getComponent<S_Passport>());
		red_stamp->getComponent<S_Stamp>()->givePassportScript(passport->getComponent<S_Passport>());


		// stamp tray was just a renderable object, so it needs to be setup here. (I cba to make it a prefab)
		stamp_tray->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/StampTray.png");
		stamp_tray->getTransform()->setLocalScale(3);

		// setup the passport.
		s_gameSceneScript->setupPassport();

		next_button->getTransform()->setLocalZheight(3);
		next_button->getTransform()->setLocalScale(8);
		next_button->addComponent<Clickable>();
		next_button->addComponent<BoxCollider>(32, 16);
		next_button->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/NextButton.png");
	}
};