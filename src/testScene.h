#pragma once

#include "Scripts/S_CharactorCreator.h"
#include "Scripts/S_AcceptDeny.h"
#include "Scripts/S_Passport.h"

class testScene : public Scene {
public:
	void load() override {

		PrefabRegistry* pref = PrefabRegistry::get();
		// load objects from prefab, add them as a child to the scene root, and save their reference 
		GameObject* character_creator = scene_root->addChild(pref->InstantiatePrefab("P_CharacterCreator", 20,20));
		GameObject* passport = scene_root->addChild(pref->InstantiatePrefab("P_Passport", 260,20));
		GameObject* green_stamp = scene_root->addChild(pref->InstantiatePrefab("P_Stamp", 688,272));
		GameObject* red_stamp = scene_root->addChild(pref->InstantiatePrefab("P_Stamp", 688, 400));
		red_stamp->getComponent<Texture>()->setTexture("../Data/Images/Pixelartimages/Stamp_red.png");

		// call the create character script on the charactor creator. 
		character_creator->getComponent<S_CharactorCreator>()->createCharacter();

		// give the passport the current character, then generate a similar one (generating similar one returns bool, true if the character is notably different)
		passport->getComponent<S_Passport>()->placeCharacter(character_creator->getComponent<S_CharactorCreator>()->getCurrentCharacter());
		passport->getComponent<S_Passport>()->setIsAccepted(character_creator->getComponent<S_CharactorCreator>()->createSimilarCharacter());

		// set passport state to the correct answer for testing. 
		passport->getChildByName("passport_accept_deny")->getComponent<S_AcceptDeny>()->setState(S_AcceptDeny::State(passport->getComponent<S_Passport>()->getIsAccepted()));
	}
};