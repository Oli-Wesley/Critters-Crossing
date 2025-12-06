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

	struct currentCharacter {
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
	void update(float dt) override;

	void setTargetPos(int x_pos);
	void setMovementSpeed(float speed);

	void createCharacter();
	bool createSimilarCharacter(); // returns true if changed enough to be a different person (in which case they must be denied). 

	std::vector<GameObject*> getCurrentCharacter();
	sf::Texture* getRandomTextureFromkey(categories);

	bool in_target_pos = 0;
	bool in_frame_pos = 0;
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
	std::map<categories, std::vector<std::pair<std::unique_ptr<sf::Texture>, float>>> asset_database;

	float change_distinct_features = 0.5;
	bool addTextureToMap(categories map_key, std::string texture_path, float spawn_probability);

	sf::Vector2f target_pos = sf::Vector2f(25, 25);
	float movement_speed = 150;
};