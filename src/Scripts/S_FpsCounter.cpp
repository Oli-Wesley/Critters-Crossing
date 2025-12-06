#include "S_FpsCounter.h"
#include "../Libraries/GameEngine/GameObject.h"


void S_FpsCounter::start()
{
	text_component = game_object->getComponent<TextComponent>();
	game_system = GameSystem::get();
}

void S_FpsCounter::update(float dt)
{
	if (display_cooldown <= 0) {
		int fps = std::round(1.0f / dt);
		if (text_component)
			text_component->setString(std::to_string(fps));
		display_cooldown = 0.05; // only change every.05 seconds
	}
	display_cooldown -= dt;
	game_object->setDrawn(game_system->isDebug());
}
