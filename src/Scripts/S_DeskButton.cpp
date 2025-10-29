#include "S_DeskButton.h"
#include "../Libraries/GameEngine/GameObject.h"

void S_DeskButton::start()
{
	tex_comp = game_object->getChildByName("Button_Sprite")->getComponent<Texture>();
	click_comp = game_object->getComponent<Clickable>();

	idle_sprite.loadFromFile("../Data/Images/Pixelartimages/Desk_button_Idle.png");
	hover_sprite.loadFromFile("../Data/Images/Pixelartimages/Desk_button_hover.png");
	click_sprite.loadFromFile("../Data/Images/Pixelartimages/Desk_button_clicked.png");
}

void S_DeskButton::update(float dt)
{
	if (click_comp->isClicked())
		tex_comp->setTexture(&click_sprite);
	else if (click_comp->isHovered()) 
		tex_comp->setTexture(&hover_sprite);
	else 
		tex_comp->setTexture(&idle_sprite);
}
