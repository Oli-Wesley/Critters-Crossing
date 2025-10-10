#include "SpriteRenderer.h"
#include "../GameObject.h"
#include "Texture.h"
#include "Transform.h"

void SpriteRenderer::render(sf::RenderWindow* target)
{
	// update sprite position based onGameobject
	sprite.setPosition(game_object->getTransform()->getGlobalPosition());
	sprite.setScale(game_object->getTransform()->getGlobalScale());
	sf::Vector2f scale = sprite.getScale();
	target->draw(sprite);
}

sf::Sprite* SpriteRenderer::getSprite()
{
	return &sprite;
}
