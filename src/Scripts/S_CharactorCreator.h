#pragma once 

#include "../Libraries/GameEngine/ScriptableBehaviour.h" 
#include <string>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

class S_CharactorCreator : public ScriptableBehaviour {

public:
	void start() override;

	void createCharacter();

	void update(float dt) override;

	sf::Texture* getRandomTextureFromArray(std::vector<std::pair<sf::Texture*, float>> array);


private:
	enum categories {
		Person,
		Clothes,
		Hair,
		FacialHair,
		Hats,
		Extras,
		Eyes // CURRENTLY UNUSED.
	};

	std::string relative_path = "../Data/Images/PeopleLayers/";
	std::map<categories, std::vector<std::pair<sf::Texture*, float>>> asset_database;



	bool addTextureToMap(categories map_key, std::string texture_path, float spawn_probability);
};