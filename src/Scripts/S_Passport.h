#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include "S_AcceptDeny.h"
#include <SFML/Graphics.hpp>

class GameObject;

class S_Passport : public ScriptableBehaviour {
public:
	void start() override;

	// array of gameObjects (character peices) and a bool for if its changed.
	void placeCharacter(std::vector<GameObject*> objects);
	void setShouldBeAccepted(bool _is_accepted);
	bool getShouldBeAccepted();

	bool checkCorrectness();

	// 0 = deny, 1 = accept, 2 = clear
	void stamp(int state);
	int getStampState();

private:
	bool should_be_accepted = false;
	GameObject* character_placement = nullptr;
	S_AcceptDeny* accept_deny_script = nullptr;
};