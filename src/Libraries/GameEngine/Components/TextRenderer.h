#pragma once

#include "IRenderable.h"
#include <SFML/Graphics/Text.hpp>

class TextRenderer : public IRenderable
{
public:
	void render(sf::RenderWindow* target) override;
	sf::Text* getText();

private:
	sf::Text text;
};