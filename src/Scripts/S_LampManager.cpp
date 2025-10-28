#include "S_LampManager.h"
#include "../Libraries/GameEngine/GameObject.h"

void S_LampManager::setActivatedCount(int count)
{
	std::vector<GameObject*> lamps = game_object->getChilderen();
	int i = 0;
	for (GameObject* lamp : lamps) {
		lamp->getChildByName("Lamp_Glow")->setDrawn(i++ < count);
	}
}
