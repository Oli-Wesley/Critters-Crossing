#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <SFML/Graphics.hpp>

class S_AcceptDeny : public ScriptableBehaviour {
public:
	// set stamp state
	enum State {
		ACCEPT,
		DENY,
		CLEAR
	};

	void setState(State state);

	State getState() { return current_state; };

	void start() override;

private:
	sf::Texture* accept_texture = new sf::Texture;
	sf::Texture* deny_texture = new sf::Texture;
	sf::Texture* no_texture = new sf::Texture;
	State current_state = CLEAR;
};