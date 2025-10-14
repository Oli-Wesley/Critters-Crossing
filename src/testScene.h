#pragma once

#include "Scripts/S_CharactorCreator.h"
#include "Scripts/S_AcceptDeny.h"

class testScene : public Scene {
public:
	void load() override {

		// load objects from prefab, add them as a child to the scene root, and save their reference 
		GameObject* test = scene_root->addChild(PrefabRegistry::get()->InstantiatePrefab("P_Character_Creator", 20,20));
		GameObject* passport = scene_root->addChild(PrefabRegistry::get()->InstantiatePrefab("P_Passport", 260,20));

		// call the create character script on the charactor creator. 
		test->getComponent<S_CharactorCreator>()->createCharacter();

		// getChild from passport, then get the accept/deny script, then set the state of the passport. (temporary for testing).
		passport->getChildByName("passport_accept_deny")->getComponent<S_AcceptDeny>()->setState(S_AcceptDeny::State::ACCEPT);
	}
};