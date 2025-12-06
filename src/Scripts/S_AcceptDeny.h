#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <SFML/Graphics.hpp>
#include <memory>

class S_AcceptDeny : public ScriptableBehaviour {
public:
	S_AcceptDeny();
	// set stamp state
	enum State {
		DENY,
		ACCEPT,
		CLEAR
	};
	void setState(State state);

	State getState() { return current_state; };

	void start() override;

private:
	std::unique_ptr<sf::Texture> accept_texture;
	std::unique_ptr<sf::Texture> deny_texture;
	std::unique_ptr<sf::Texture> no_texture;
	State current_state = CLEAR;
};