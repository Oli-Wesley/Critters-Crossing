#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <SFML/Graphics.hpp>
#include "../Libraries/GameEngine/Components/TextComponent.h"
#include "../Libraries/GameEngine/Systems/GameSystem.h"
class GameObject;

class S_FpsCounter : public ScriptableBehaviour {
public:
	void start() override;
	void update(float dt) override;
private:
	TextComponent* text_component = nullptr;
	float display_cooldown = 0;
	GameSystem* game_system = nullptr;
};