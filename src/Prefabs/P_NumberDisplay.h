#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_ScoreDisplay.h"

REGISTER_PREFAB(
	P_NumberDisplay,            // name
	[]() -> GameObject* // lambda construction func
	{
		GameObject* game_object = new GameObject("Number_Display");
		TextComponent* text_comp = game_object->addComponent<TextComponent>();
		game_object->addComponent<TextRenderer>();
		game_object->getTransform()->setLocalZheight(1);

		text_comp->setFont("../Data/Fonts/PixelFont.ttf");
		text_comp->setCharacterSize(10);
		text_comp->setFillColor(sf::Color(34, 32, 52));

		// add score display component with zero lenght of 10;
		game_object->addScript<S_ScoreDisplay>()->setZeroLength(10);
		return game_object;
	});