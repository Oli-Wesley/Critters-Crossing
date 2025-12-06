#include "S_AcceptDeny.h"
#include "../Libraries/GameEngine.h"

S_AcceptDeny::S_AcceptDeny()
{
	accept_texture = std::make_unique<sf::Texture>();
	deny_texture = std::make_unique<sf::Texture>();
	no_texture = std::make_unique<sf::Texture>();
}

void S_AcceptDeny::setState(S_AcceptDeny::State state) {
	if (state != current_state) {
		if (state == ACCEPT)
			game_object->getComponent<Texture>()->setTexture(accept_texture.get());
		else if (state == DENY)
			game_object->getComponent<Texture>()->setTexture(deny_texture.get());
		else if (state == CLEAR)
			game_object->getComponent<Texture>()->setTexture(no_texture.get());

		current_state = state;
	}
}

void S_AcceptDeny::start()
{
	accept_texture->loadFromFile("../Data/Images/PassportLayers/Passport_accept.png");
	deny_texture->loadFromFile("../Data/Images/PassportLayers/Passport_deny.png");
	no_texture->loadFromFile("../Data/Images/PeopleLayers/extras/NONE.png");
}
