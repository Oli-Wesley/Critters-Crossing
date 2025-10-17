#include "S_AcceptDeny.h"
#include "../Libraries/GameEngine.h"

void S_AcceptDeny::setState(S_AcceptDeny::State state) {
	if (state != current_state) {
		if (state == ACCEPT)
			game_object->getComponent<Texture>()->setTexture(accept_texture);
		else if (state == DENY)
			game_object->getComponent<Texture>()->setTexture(deny_texture);
		else if (state == CLEAR)
			game_object->getComponent<Texture>()->setTexture(no_texture);

		current_state = state;
	}
}

void S_AcceptDeny::start()
{
	accept_texture->loadFromFile("../Data/Images/PassportLayers/Passport_accept.png");
	deny_texture->loadFromFile("../Data/Images/PassportLayers/Passport_deny.png");
	no_texture->loadFromFile("../Data/Images/PeopleLayers/extras/NONE.png");
}
