#pragma once

#pragma once

#include "../GameObject.h"
#include "BoxCollider.h"
#include "IComponent.h"
#include "IScriptableBehaviour.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Clickable : public IComponent
{
public:
	void update(float dt) override;

private:
	bool wasHovered;
	bool wasPressed;
	bool checkPointCol(sf::FloatRect bounds, sf::Vector2i _pos);
};