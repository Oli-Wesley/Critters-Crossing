#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_FpsCounter.h"

REGISTER_PREFAB(
	P_FPSCounter,            // name
	[]() -> std::unique_ptr<GameObject> // lambda construction func
	{
		std::unique_ptr<GameObject> game_object = std::make_unique<GameObject>("FPS_Display");
		TextComponent* text_comp = game_object->addComponent<TextComponent>();
		game_object->addComponent<TextRenderer>();
		game_object->getTransform()->setLocalZheight(500);

		text_comp->setFont("../Data/Fonts/PixelFont.ttf");
		text_comp->setCharacterSize(30);
		text_comp->setFillColor(sf::Color(255, 0, 255));

		game_object->addScript<S_FpsCounter>();
		return game_object;
	});