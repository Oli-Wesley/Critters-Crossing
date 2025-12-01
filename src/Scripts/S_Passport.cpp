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

void S_Passport::setIsAccepted(bool _is_accepted)
{
	is_accepted = _is_accepted;
}

bool S_Passport::getIsAccepted()
{
	return is_accepted;
}

void S_Passport::stamp(int state)
{
	if (game_object->isDrawn()) {
		accept_deny_script->setState(S_AcceptDeny::State(state));
		// check if the stamp is correct (static cast to stop the warnings...)
		if (is_accepted == static_cast<bool>(state))
			is_current_stamp_correct = 1;
		else
			is_current_stamp_correct = 0;
		// std::cout << is_current_stamp_correct << "\n";
	}
}

int S_Passport::getStampState()
{
	return accept_deny_script->getState();
}
