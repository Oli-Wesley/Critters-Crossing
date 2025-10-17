#pragma once 
#include "Clickable.h"

class Draggable : public Clickable {
public:
	void update(float dt) override;
private:
	sf::Vector2f relative_mouse_pos;
	bool is_held = false;
};