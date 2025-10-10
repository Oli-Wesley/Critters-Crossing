#pragma once
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 

class TestScript : public ScriptableBehaviour {
	void update(float dt) override {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			game_object->getTransform()->rotateAroundPoint(-250 * dt);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			game_object->getTransform()->rotateAroundPoint(250 * dt);

		game_object->getComponent<TestScript>()->test();
	}

	void test() {
		std::cout << "Holy it works!, first try babeeeeee" << std::endl;
	}
};