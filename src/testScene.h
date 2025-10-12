#pragma once

#include "Scripts/S_CharactorCreator.h"

class testScene : public Scene {
public:
	void load() override {

		GameObject* test = PrefabRegistry::get()->InstantiatePrefab("P_Character_Creator");
		scene_root->addChild(test);
		test->getTransform()->setLocalScale(5, 5);

		test->getComponent<S_CharactorCreator>()->createCharacter();

	}
};