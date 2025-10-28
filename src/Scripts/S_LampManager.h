#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <SFML/Graphics.hpp>

class GameObject;

class S_LampManager : public ScriptableBehaviour {
public:
	void setActivatedCount(int count);

private:
	int activated_lamps = 0;
};