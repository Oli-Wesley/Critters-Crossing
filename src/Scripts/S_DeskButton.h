#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <SFML/Graphics.hpp>
#include "../Libraries/GameEngine/Components/Texture.h"
#include "../Libraries/GameEngine/Components/Clickable.h"

class GameObject;

class S_DeskButton : public ScriptableBehaviour {
public:
	void start() override;
	void update(float dt) override;


private:
	Texture* tex_comp = nullptr;
	Clickable* click_comp = nullptr;

	sf::Texture idle_sprite;
	sf::Texture hover_sprite;
	sf::Texture click_sprite;
};