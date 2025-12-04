#pragma once
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include "../Libraries/GameEngine/Components/TextComponent.h"

class GameObject;

class S_ScoreDisplay : public ScriptableBehaviour {
public: 
	void start() override;
	// default 10
	void setZeroLength(int zero_length);
	void setvalue(int value);

private: 
	int length = 0;
	int current_value = 0;
	TextComponent* text_component;

	std::string fillToLength(std::string string);

};