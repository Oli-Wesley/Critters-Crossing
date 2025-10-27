#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include "S_CharactorCreator.h"
#include "S_Passport.h"
#include "../Libraries/GameEngine/Components/Clickable.h"
#include <SFML/Graphics.hpp>

class S_GameSceneManager : public ScriptableBehaviour {
public:
	void start() override;
	void update(float dt) override;
	void setupPassport();
	void checkResult();

	
private:
	S_CharactorCreator* s_character_creator = nullptr;
	S_Passport* s_passport = nullptr;
	GameObject* obj_passport = nullptr;
	Clickable* c_next_button = nullptr;
	GameObject* obj_character_creator = nullptr;

};