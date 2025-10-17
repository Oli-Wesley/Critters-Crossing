#pragma once 

#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <string>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

class S_CharactorCreator : public ScriptableBehaviour {
private:
	enum categories {
		Person,
		Clothes,
		Hair,
		FacialHair,
		Hats,
		Extras,
		Eyes
	};

	struct currentCharacter{
		int person = -1;
		int clothes = -1;
		int hair = -1;
		int facial_hair = -1;
		int hats = -1;
		int extras = -1;
		int eyes = -1;
	};

public:
	void start() override;

	void createCharacter(); 
	bool createSimilarCharacter(); // returns true if changed enough to be a different person (in which case they must be denied). 

	std::vector<GameObject*> getCurrentCharacter();
	sf::Texture* getRandomTextureFromkey(categories);


private:
	GameObject* person_obj = nullptr;
	GameObject* clothes_obj = nullptr;
	GameObject* hair_obj = nullptr;
	GameObject* facial_hair_obj = nullptr;
	GameObject* hats_obj = nullptr;
	GameObject* extras_obj = nullptr;
	GameObject* eyes_obj = nullptr;

	currentCharacter current_character;

	std::string relative_path = "../Data/Images/PeopleLayers/";
	std::map<categories, std::vector<std::pair<sf::Texture*, float>>> asset_database;

	float change_distinct_features = 0.5;

	float recreate_cooldown = 0;

	bool addTextureToMap(categories map_key, std::string texture_path, float spawn_probability);
};