#include "S_GameSceneManager.h"
#include "../Libraries/GameEngine/GameObject.h"

#pragma once 

void S_GameSceneManager::start()
{

}

void S_GameSceneManager::update(float dt)
{
	if (s_character_creator == nullptr || s_passport == nullptr || obj_character_creator == nullptr || obj_passport == nullptr) {
		obj_passport = game_object->getChildByName("Passport");
		s_passport = obj_passport->getComponent<S_Passport>();
		obj_character_creator = game_object->getChildByName("Character_Creator");
		s_character_creator = obj_character_creator->getComponent<S_CharactorCreator>();
	}

	if (s_character_creator->in_frame_pos) {
		obj_passport->setDrawn(1);
	}
}

void S_GameSceneManager::setupPassport()
{
	if (s_character_creator == nullptr || s_passport == nullptr || obj_character_creator == nullptr || obj_passport == nullptr) {
		obj_passport = game_object->getChildByName("Passport");
		s_passport = obj_passport->getComponent<S_Passport>();
		obj_character_creator = game_object->getChildByName("Character_Creator");
		s_character_creator = obj_character_creator->getComponent<S_CharactorCreator>();
	}

	// call the create character script on the charactor creator. 
	s_character_creator->createCharacter();
	// give the passport the current character, then generate a similar one (generating similar one returns bool, true if the character is notably different)
	s_passport->placeCharacter(s_character_creator->getCurrentCharacter());
	s_passport->setIsAccepted(s_character_creator->createSimilarCharacter());

	obj_character_creator->getTransform()->setLocalPosition(-180, 25);
	s_character_creator->setTargetPos(25);
	s_character_creator->setMovementSpeed(100);
}

void S_GameSceneManager::checkResult()
{
	if (s_passport->getStampState() != 2) // if has been stamped
	{
		// hide passport, 
		// obj_passport->setDrawn(0);

		// send person in direction of stamp regardless of if it was correct or not.
		if (s_passport->getStampState())
		{
			s_character_creator->setTargetPos(400);
		}
		else {
			s_character_creator->setTargetPos(-180);
		}

		// TODO: stuff if its incorrect (score/remove lives/something idk)
		if (s_passport->isCorrect())
		{
			std::cout << "CORRECT \n";
		}
		else {
			std::cout << "INCORRECT \n";
		}
	}
}
