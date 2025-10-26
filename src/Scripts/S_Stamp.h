#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <SFML/Graphics.hpp>
#include "S_Passport.h"

class GameObject;

class S_Stamp : public ScriptableBehaviour {
public:
	void start() override;
	void update(float dt) override;
	void onTriggerStay(GameObject*) override;

	void givePassportScript(S_Passport* script);

private:
	
	int is_green_stamp = -1;
	S_Passport* passport_script = nullptr;
};