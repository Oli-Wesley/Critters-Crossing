#include "S_Stamp.h"
#include "../Libraries/GameEngine.h" 

void S_Stamp::start()
{
}

void S_Stamp::update(float dt)
{
	// after names assigned, set the type of stamp it is.
	std::string name = game_object->getName();
	if (is_green_stamp == -1 && name != "stamp_none") {
		if (name == "stamp_green")
			is_green_stamp = 1;

		else if (name == "stamp_red")
			is_green_stamp = 0;

		// get start position. 
		start_pos = game_object->getTransform()->getGlobalPosition();
	}

	// snap back to start position 
	if (!game_object->getComponent<Draggable>()->isHeld())
		game_object->getTransform()->setGlobalPosition(start_pos);
}

void S_Stamp::onTriggerStay(GameObject* other)
{
	if (other->getName() == "Passport Trigger") {
		sf::FloatRect this_col = game_object->getComponent<BoxCollider>()->getCollider();
		sf::FloatRect other_col = other->getComponent<BoxCollider>()->getCollider();
		// check if fully inside the other collider.
		if ((this_col.left > other_col.left) && (this_col.top > other_col.top) && (this_col.left + this_col.width < other_col.left + other_col.width) && (this_col.top + this_col.height < other_col.top + other_col.height)) {
			// stamp passport if isnt the same state as current stamp. 
			if (passport_script->getStampState() != is_green_stamp)
			{
				passport_script->stamp(is_green_stamp);
			}
		}
	}
}

void S_Stamp::givePassportScript(S_Passport* script)
{
	passport_script = script;
}
