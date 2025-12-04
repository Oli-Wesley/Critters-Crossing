#pragma once 
#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <SFML/Graphics.hpp>
#include <fstream>


class GameObject;

class S_GlobalData : public ScriptableBehaviour {
public:
	int score = 0;
	int high_score = 0;

	void start() override;
	void onDestroy() override;
private:	
};