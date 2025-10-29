#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_DeskButton.h"

REGISTER_PREFAB(
	P_Desk,            // name
	[]() -> GameObject* // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* game_object = pref->InstantiatePrefab("P_RenderableObject", "Desk");
		game_object->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Desk.png");
		game_object->addComponent<Clickable>();
		game_object->getTransform()->setLocalScale(2.5);
		game_object->getTransform()->setLocalZheight(5);
		BoxCollider* col = game_object->addComponent<BoxCollider>(16,13);
		col->setPosition(125, 4);

		// button sprite. (load, get texture component and set it to the idle texture)
		game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "Button_Sprite"))->getTransform()->setLocalPosition(48,2);

		game_object->addScript<S_DeskButton>();
		// MAKE CLICKABLE, THEN MAKE SCRIPT
		// THEN SCRIPT EDITS SPRITES ON CHILDREN.
		// THEN GAMEMANAGER FINDS THIS INSTEAD.
		// THEN RUN SAME STUFF AS IF WAS PREVIOUS BUTTON SETUP
		// ET VOILA AND ITS DONE

		return game_object;
	});