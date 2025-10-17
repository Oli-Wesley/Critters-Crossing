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
	void setIsAccepted(bool _is_accepted);
	bool getIsAccepted();

private:
	bool is_accepted = false;
	GameObject* character_placement = nullptr;
	S_AcceptDeny* accept_deny_script = nullptr;
};