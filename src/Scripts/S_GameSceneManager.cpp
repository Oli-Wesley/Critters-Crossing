#include "S_GameSceneManager.h"
#include "../Libraries/GameEngine/GameObject.h"
#include "../Libraries/GameEngine/Systems/GameSystem.h"
#include "../Libraries/GameEngine/Scene.h"
#include "S_GlobalData.h"
#include <iostream>

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
	// generate another character if similar enough to be accepted set passports accepted value to true.
	s_passport->setShouldBeAccepted(s_character_creator->createSimilarCharacter());

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
		// accepted stamp
		if (s_passport->getStampState())
		{
			s_character_creator->setTargetPos(720);
			s_character_creator->setMovementSpeed(200);
		}
		// denied stamp
		else {
			s_character_creator->setTargetPos(-250);
		}

		// correct stamp for the character
		if (s_passport->checkCorrectness()) {
			correct_count++;
			if (GameSystem::get()->isDebug())
				std::cout << "passport has been stamped correctly\n";
		}
		else {
			incorrect_count++;
			if (GameSystem::get()->isDebug())
				std::cout << "passport has been stamped incorrectly\n";
		}

		s_passport->stamp(2); // clear passport
		obj_passport->setDrawn(0);
	}
}

void S_GameSceneManager::gameOver()
{
	GameObject* dont_destroy = GameSystem::get()->getCurrentScene()->dont_destroy.get();

	// fallback to create global data here, incase title screen was never run (SHOULD NEVER HAPPEN IN GAMEPLAY, BUT HAPPENS IN TESTING DUE TO LOADING THE SCENES DIRECTLY AND SKIPPING TITLE SCENE)
	if (dont_destroy->getChildByName("global_data") == nullptr) {
		dont_destroy->addChild(std::make_unique<GameObject>("global_data"))->addScript<S_GlobalData>();
	}

	// set score and high score to global data.
	S_GlobalData* global_data = GameSystem::get()->getCurrentScene()->dont_destroy->getChildByName("global_data")->getComponent<S_GlobalData>();
	global_data->score = correct_count;
	if (correct_count > global_data->high_score)
		global_data->high_score = correct_count;

	GameSystem::get()->switchScene("GameOverScene");
}
