#include "S_GameSceneManager.h"
#include "../Libraries/GameEngine/GameObject.h"
#include "../Libraries/GameEngine/Systems/GameSystem.h"
#include "../Libraries/GameEngine/Scene.h"
#include "S_GlobalData.h"

#pragma once 

void S_GameSceneManager::start()
{

}

void S_GameSceneManager::update(float dt)
{
	// if any are null, fetch all again (not the best way, ideally use seperate ones, but once its found 1 it should find them all so not that bad)
	if (s_character_creator == nullptr || s_passport == nullptr || obj_character_creator == nullptr || obj_passport == nullptr || c_next_button == nullptr) {
		obj_passport = game_object->getChildByName("Passport");
		s_passport = obj_passport->getComponent<S_Passport>();
		obj_character_creator = game_object->getChildByName("Character_Creator");
		s_character_creator = obj_character_creator->getComponent<S_CharactorCreator>();
		c_next_button = game_object->getChildByName("Desk")->getComponent<Clickable>();
	}

	// when character is in the frame position. 
	if (s_character_creator->in_frame_pos) {
		obj_passport->setDrawn(1);
		// when button to proceed is hit.
		if (c_next_button->isClicked()) {
			checkResult();
		}
	}

	// when character reaches target position off screen. 
	if (!s_character_creator->in_frame_pos && s_character_creator->in_target_pos) {
		setupPassport();
		s_lamp_manager->setActivatedCount(incorrect_count);
		if (incorrect_count >= 3)
			gameOver();
	}
}

void S_GameSceneManager::setupPassport()
{
	// if any are null, fetch all again (not the best way, ideally use seperate ones, but once its found 1 it should find them all so not that bad)
	if (s_character_creator == nullptr || s_passport == nullptr || obj_character_creator == nullptr || obj_passport == nullptr || c_next_button == nullptr) {
		obj_passport = game_object->getChildByName("Passport");
		s_passport = obj_passport->getComponent<S_Passport>();
		obj_character_creator = game_object->getChildByName("Character_Creator");
		s_character_creator = obj_character_creator->getComponent<S_CharactorCreator>();
		c_next_button = game_object->getChildByName("Desk")->getComponent<Clickable>();
	}

	// call the create character script on the charactor creator. 
	s_character_creator->createCharacter();
	// give the passport the current character, then generate a similar one (generating similar one returns bool, true if the character is notably different)
	s_passport->placeCharacter(s_character_creator->getCurrentCharacter());
	s_passport->setIsAccepted(s_character_creator->createSimilarCharacter());

	obj_character_creator->getTransform()->setLocalPosition(-250, 25);
	s_character_creator->setTargetPos(25);
	s_character_creator->setMovementSpeed(150);
}

void S_GameSceneManager::checkResult()
{
	if (s_passport->getStampState() != 2) // if has been stamped
	{
		if (s_lamp_manager == nullptr)
			s_lamp_manager = game_object->getChildByName("Lamp_Manager")->getComponent<S_LampManager>();

		// send person in direction of stamp regardless of if it was correct or not.
		if (s_passport->getStampState())
		{
			s_character_creator->setTargetPos(720);
			s_character_creator->setMovementSpeed(200);
		}
		else {
			s_character_creator->setTargetPos(-250);
		}

		if (s_passport->isCorrect())
		{
			correct_count++;
		}
		else {
			incorrect_count++;
		}
		s_passport->stamp(2); // clear passport
		obj_passport->setDrawn(0);
	}
}

void S_GameSceneManager::gameOver()
{
	GameObject* test =GameSystem::get()->getCurrentScene()->dont_destroy;
	GameSystem::get()->getCurrentScene()->dont_destroy->getChildByName("global_data")->getComponent<S_GlobalData>()->score = correct_count;
	GameSystem::get()->switchScene("GameOverScene");
}
