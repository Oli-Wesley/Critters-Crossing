#include "S_CharactorCreator.h"
#include "../Libraries/GameEngine.h"
#include <iostream>

void S_CharactorCreator::start() 
{
	// LOAD ALL THE FILES. and give them probabilities. 
	// people 
	addTextureToMap(Person, "People/person 1.png", 1); // all probabilities the same, so all should spawn at the same frequency.
	addTextureToMap(Person, "People/person 2.png", 1);
	addTextureToMap(Person, "People/person 3.png", 1);
	addTextureToMap(Person, "People/person 4.png", 1);
	// Clothes
	addTextureToMap(Clothes, "Clothes/blue hoodie.png", 1);
	addTextureToMap(Clothes, "Clothes/green hoodie.png", 1);
	addTextureToMap(Clothes, "Clothes/red hoodie.png", 1);

	addTextureToMap(Clothes, "Clothes/purple tshirt.png", 1);
	addTextureToMap(Clothes, "Clothes/orange tshirt.png", 1);
	addTextureToMap(Clothes, "Clothes/white tshirt.png", 1);
	// hair
	addTextureToMap(Hair, "extras/NONE.png", 1); // NONE for no Texture (bald).
	addTextureToMap(Hair, "Hair/black fluffy.png", 1);
	addTextureToMap(Hair, "Hair/blond fluffy.png", 1);
	addTextureToMap(Hair, "Hair/ginger fluffy.png", 1);
	addTextureToMap(Hair, "Hair/brown fluffy.png", 1);

	addTextureToMap(Hair, "Hair/black long.png", 1);
	addTextureToMap(Hair, "Hair/blond long.png", 1);
	addTextureToMap(Hair, "Hair/ginger long.png", 1);
	addTextureToMap(Hair, "Hair/brown long.png", 1);
	// facial hair
	addTextureToMap(FacialHair, "extras/NONE.png", 10); // higher probability to have no beard.
	addTextureToMap(FacialHair, "facial hair/black beard.png", 1); 
	addTextureToMap(FacialHair, "facial hair/brown beard.png", 1);
	addTextureToMap(FacialHair, "facial hair/ginger beard.png", 1);

	addTextureToMap(FacialHair, "facial hair/black Mustache Beard.png", 1);
	addTextureToMap(FacialHair, "facial hair/brown Mustache Beard.png", 1);
	addTextureToMap(FacialHair, "facial hair/ginger Mustache Beard.png", 1);

	addTextureToMap(FacialHair, "facial hair/black mustache.png", 1);
	addTextureToMap(FacialHair, "facial hair/brown mustache.png", 1);
	addTextureToMap(FacialHair, "facial hair/ginger mustache.png", 1);

	addTextureToMap(FacialHair, "facial hair/brown stubble.png", 1);
	addTextureToMap(FacialHair, "facial hair/ginger stubble.png", 1);
	// hats
	addTextureToMap(Hats, "extras/NONE.png", 6); // 50% chance to have no hats
	addTextureToMap(Hats, "hats/beanie 1.png", 1);
	addTextureToMap(Hats, "hats/beanie 2.png", 1);
	addTextureToMap(Hats, "hats/beanie 3.png", 1);
	addTextureToMap(Hats, "hats/bucket hat.png", 1);
	addTextureToMap(Hats, "hats/cap.png", 1);
	addTextureToMap(Hats, "hats/top hat.png", 1);
	// extras
	addTextureToMap(Extras, "extras/NONE.png", 20); // 66% chance to have no extras
	addTextureToMap(Extras, "extras/glasses.png", 9); 
	addTextureToMap(Extras, "extras/overalls.png", 1); // super rare mario overalls.  
}

// actually create the character.
void S_CharactorCreator::createCharacter()
{
	std::vector <GameObject*> childeren = game_object->getAllChilderen();
	// Get children and set their texture from a random, weighted texture from the corresponding asset database array
	for (GameObject* child : childeren) {
		if (child->getName() == "person")
		{
			child->getComponent<Texture>()->setTexture(getRandomTextureFromArray(asset_database[Person]));
		}
		else if (child->getName() == "clothes") 
		{
			child->getComponent<Texture>()->setTexture(getRandomTextureFromArray(asset_database[Clothes]));
		}
		else if (child->getName() == "hair") 
		{
			child->getComponent<Texture>()->setTexture(getRandomTextureFromArray(asset_database[Hair]));
		}
		else if (child->getName() == "facial_hair") 
		{
			child->getComponent<Texture>()->setTexture(getRandomTextureFromArray(asset_database[FacialHair]));
		}
		else if (child->getName() == "hat") 
		{
			child->getComponent<Texture>()->setTexture(getRandomTextureFromArray(asset_database[Hats]));
		}
		else if (child->getName() == "extras") 
		{
			child->getComponent<Texture>()->setTexture(getRandomTextureFromArray(asset_database[Extras]));
		}
	}
}

void S_CharactorCreator::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		createCharacter();
}

sf::Texture* S_CharactorCreator::getRandomTextureFromArray(std::vector<std::pair<sf::Texture*, float>> array)
{
	// Calculate total weight
	float total_weight = 0.0f;
	for (std::pair<sf::Texture*, float> pair : array)
		total_weight += pair.second;

	
	float random_value = static_cast<float>(rand()) / RAND_MAX * total_weight;


	// Select based on weighted probability
	float cumulative = 0.0f;
	for (const auto& pair : array) {
		cumulative += pair.second;
		if (random_value <= cumulative)
			return pair.first;
	}

	return nullptr;
}

// map_key = catagory that it can be. 
bool S_CharactorCreator::addTextureToMap(categories map_key, std::string texture_path, float spawn_probability)
{
	sf::Texture* tex = new sf::Texture;
	if (tex->loadFromFile(relative_path + texture_path));
	{
		std::pair<sf::Texture*, float> pair = { tex, spawn_probability };
		asset_database[map_key].push_back(pair);
		return 1;
	}
	std::cout << "failed to load texture: " << relative_path + texture_path << std::endl;
	return 0;
}
