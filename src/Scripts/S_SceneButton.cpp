#include "S_SceneButton.h"
#include "../Libraries/GameEngine.h"

S_SceneButton::S_SceneButton(std::string target_scene, std::string defaulttex, std::string hover, std::string click)
{
	target = target_scene;
	default_tex.loadFromFile(defaulttex);
	hover_tex.loadFromFile(hover);
	click_tex.loadFromFile(click);

}

void S_SceneButton::start()
{
	tex_component = game_object->getComponent<Texture>();
	click_component = game_object->getComponent<Clickable>();
	tex_component->setTexture(&default_tex);
}

void S_SceneButton::update(float dt)
{
	
	if (click_component->isClicked())
	{
		tex_component->setTexture(&click_tex);
		if (target == "~quit~") {
			GameSystem::get()->getWindow()->close();
		}
		GameSystem::get()->switchScene(target);
	}
	else if (click_component->isHovered())
		tex_component->setTexture(&hover_tex);
	else
		tex_component->setTexture(&default_tex);
}
