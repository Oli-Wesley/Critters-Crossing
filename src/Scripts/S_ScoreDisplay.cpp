#include "S_ScoreDisplay.h"
#include "../Libraries/GameEngine/GameObject.h"

void S_ScoreDisplay::start()
{
	text_component = game_object->getComponent<TextComponent>();
	text_component->setString(fillToLength(""));
}

void S_ScoreDisplay::setZeroLength(int zero_length)
{
	length = zero_length;
	text_component->setString(fillToLength(std::to_string(current_value)));
}

void S_ScoreDisplay::setvalue(int value)
{
	current_value = value;
	text_component->setString(fillToLength(std::to_string(current_value)));
}

std::string S_ScoreDisplay::fillToLength(std::string string)
{
	// while string lenght is less than desired. 
	while (string.size() < length)
		string = "0" + string;
	return string;
}