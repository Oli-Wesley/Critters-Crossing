#pragma once

#include "Scripts/S_CharactorCreator.h"
#include "Scripts/S_AcceptDeny.h"
#include "Scripts/S_Passport.h"

class testScene : public Scene {
public:
	void load() override {

		// load objects from prefab, add them as a child to the scene root, and save their reference 
		GameObject* test = scene_root->addChild(PrefabRegistry::get()->InstantiatePrefab("P_Character_Creator", 20,20));
		GameObject* passport = scene_root->addChild(PrefabRegistry::get()->InstantiatePrefab("P_Passport", 260,20));

		// call the create character script on the charactor creator. 
		test->getComponent<S_CharactorCreator>()->createCharacter();

		// give the passport the current character, then generate a similar one (generating similar one returns bool, true if the character is notably different)
		passport->getComponent<S_Passport>()->placeCharacter(test->getComponent<S_CharactorCreator>()->getCurrentCharacter());
		passport->getComponent<S_Passport>()->setIsAccepted(test->getComponent<S_CharactorCreator>()->createSimilarCharacter());

		// set passport state to the correct answer for testing. 
		passport->getChildByName("passport_accept_deny")->getComponent<S_AcceptDeny>()->setState(S_AcceptDeny::State(passport->getComponent<S_Passport>()->getIsAccepted()));
		std::cout << passport->getComponent<S_Passport>()->getIsAccepted();
	}
};