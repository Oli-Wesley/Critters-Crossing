#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include "../Libraries/GameEngine/Components/Texture.h" 
#include "../Libraries/GameEngine/Components/Clickable.h" 
#include <SFML/Graphics.hpp>

class GameObject;

class S_SceneButton : public ScriptableBehaviour {
public:
	// target scene, default texture, hover texture, click texture (paths)
	S_SceneButton(std::string target_scene, std::string defaulttex, std::string hover, std::string click);
	void start() override;
	void update(float dt) override;


private:
	sf::Texture default_tex;
	sf::Texture hover_tex;
	sf::Texture click_tex;
	std::string target;

	Texture* tex_component = nullptr;
	Clickable* click_component = nullptr;
};