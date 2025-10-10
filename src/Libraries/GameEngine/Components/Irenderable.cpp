#pragma once

#include "IRenderable.h"
#include "../GameObject.h"

// returns the renderOrder, used for sorting the render_queue so elements get
// drawn in the correct order.
float IRenderable::getRenderOrder()
{
	return game_object->getTransform()->getGlobalZheight();
}
