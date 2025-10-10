#include "TextRenderer.h"
#include "../GameObject.h"
#include "Transform.h"

void TextRenderer::render(sf::RenderWindow* target)
{
	// update text position based on GameObject
	text.setPosition(game_object->getTransform()->getGlobalPosition());
	text.setScale(game_object->getTransform()->getGlobalScale());
	target->draw(text);
}

sf::Text* TextRenderer::getText()
{
	return &text;
}