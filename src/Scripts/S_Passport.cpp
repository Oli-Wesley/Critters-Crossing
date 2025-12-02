#include "S_Passport.h"
#include "../Libraries/GameEngine.h"

void S_Passport::start()
{
	character_placement = game_object->getChildByName("passport_person");
	accept_deny_script = game_object->getChildByName("passport_accept_deny")->getComponent<S_AcceptDeny>();
}

void S_Passport::placeCharacter(std::vector<GameObject*> objects)
{
	std::vector<GameObject*> childeren = character_placement->getAllChilderen();
	int count = 0;
	for (GameObject* object : objects) {
		childeren[count]->getComponent<Texture>()->setTexture(object->getComponent<Texture>()->getTexture());
		childeren[count++]->getTransform()->setLocalZheight(object->getTransform()->getLocalZheight());
	}
}

void S_Passport::setShouldBeAccepted(bool _is_accepted)
{
	should_be_accepted = _is_accepted;
}

bool S_Passport::getShouldBeAccepted()
{
	return should_be_accepted;
}

bool S_Passport::checkCorrectness()
{
	bool stamp_state = getStampState(); // true stamped accept, false if stamped deny

	if (should_be_accepted == stamp_state)
		return true;
	return false;
}

void S_Passport::stamp(int state)
{
	if (game_object->isDrawn()) {
		accept_deny_script->setState(S_AcceptDeny::State(state)); // set texture
	}
}

int S_Passport::getStampState()
{
	return accept_deny_script->getState();
}
