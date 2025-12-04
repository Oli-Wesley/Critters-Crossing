#include "S_SceneButton.h"
#include "../Libraries/GameEngine.h"

// name of the target scene, idle texture, hover texture, and clicktexture (needs all of them given, but they can refer to the same texture).
S_SceneButton::S_SceneButton(std::string target_scene, std::string defaulttex, std::string hover)
{
	target = target_scene;
	default_tex.loadFromFile(defaulttex);
	hover_tex.loadFromFile(hover);
}

void S_SceneButton::start()
{
	tex_component = game_object->getComponent<Texture>();
	click_component = game_object->getComponent<Clickable>();
	tex_component->setTexture(&default_tex);
}

void S_SceneButton::update(float dt)
{
	if (click_component->isHovered())
		tex_component->setTexture(&hover_tex);
	else
		tex_component->setTexture(&default_tex);
}

void S_SceneButton::onClick()
{
	if (target == "~quit~") {
		GameSystem::get()->getWindow()->close();
	}
	GameSystem::get()->switchScene(target);
}
