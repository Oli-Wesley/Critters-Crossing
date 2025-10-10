#include "Clickable.h"
#include "../Systems/GameSystem.h"

void Clickable::update(float dt)
{
	BoxCollider* collider = game_object->getComponent<BoxCollider>();
	// if any of the needed components dont exist, return.
	if (!game_object->isActive() || collider == nullptr)
		return;

	sf::Vector2i mousePos =
		sf::Mouse::getPosition(*GameSystem::get()->getWindow());

	bool isHovering = checkPointCol(collider->getCollider(), mousePos);
	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	// Hover enter
	if (isHovering && !wasHovered)
	{
		for (auto* comp : game_object->getAllComponents())
		{
			if (auto* script = dynamic_cast<IScriptableBehaviour*>(comp))
			{
				script->onHover();
			}
		}
	}

	// Hover exit
	if (!isHovering && wasHovered)
	{
		for (auto* comp : game_object->getAllComponents())
		{
			if (auto* script = dynamic_cast<IScriptableBehaviour*>(comp))
			{
				script->onStopHover();
			}
		}
	}

	wasHovered = isHovering;

	// Click
	if (isHovering && isPressed && !wasPressed)
	{
		for (auto* comp : game_object->getAllComponents())
		{
			if (auto* script = dynamic_cast<IScriptableBehaviour*>(comp))
			{
				script->onClick();
			}
		}
	}

	// Release
	if (wasPressed && !isPressed && isHovering)
	{
		for (auto* comp : game_object->getAllComponents())
		{
			if (auto* script = dynamic_cast<IScriptableBehaviour*>(comp))
			{
				script->onRelease();
			}
		}
	}

	wasPressed = isPressed;
}

bool Clickable::checkPointCol(sf::FloatRect bounds, sf::Vector2i _pos)
{
	return (
		bounds.left <= _pos.x && _pos.x <= bounds.left + bounds.width &&
		bounds.top <= _pos.y && _pos.y <= bounds.top + bounds.height);
}
