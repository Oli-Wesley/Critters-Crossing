#include "ScriptableTest.h"
#include "../GameObject.h"
#include <iostream>

void ScriptableTest::onTriggerEnter(GameObject*)
{
	std::cout << "GameObject: " << game_object->getName() << ", ";
	std::cout << "onTriggerEnter called\n";
}

void ScriptableTest::onTriggerStay(GameObject*)
{
	std::cout << "GameObject: " << game_object->getName() << ", ";
	std::cout << "onTriggerStay called\n";
}

void ScriptableTest::onTriggerExit(GameObject*)
{
	std::cout << "GameObject: " << game_object->getName() << ", ";
	std::cout << " onTriggerExit called\n";
}

void ScriptableTest::onCollision(GameObject*)
{
	std::cout << "GameObject: " << game_object->getName() << ", ";
	std::cout << "onCollision called\n";
}

void ScriptableTest::onClick()
{
	std::cout << "GameObject: " << game_object->getName() << ", ";
	std::cout << "onClick called\n";
}

void ScriptableTest::onRelease()
{
	std::cout << "GameObject: " << game_object->getName() << ", ";
	std::cout << "onRelease called\n";
}

void ScriptableTest::onHover()
{
	std::cout << "GameObject: " << game_object->getName() << ", ";
	std::cout << "onHover called\n";
}

void ScriptableTest::onStopHover()
{
	std::cout << "GameObject: " << game_object->getName() << ", ";
	std::cout << "onStopHover called\n";
}
