#include "S_CharactorCreator.h"
#include "../Libraries/GameEngine.h"

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
	// eyes
	addTextureToMap(Eyes, "eyes/eyes 1.png", 1);
	addTextureToMap(Eyes, "eyes/eyes 2.png", 5);
	addTextureToMap(Eyes, "eyes/eyes 3.png", 5);
	addTextureToMap(Eyes, "eyes/eyes 4.png", 0.5);

	// hats 
	addTextureToMap(Hats, "extras/NONE.png", 6); // 50% chance to have no hats
	addTextureToMap(Hats, "hats/beanie 1.png", 1);
	addTextureToMap(Hats, "hats/beanie 2.png", 1);
	addTextureToMap(Hats, "hats/beanie 3.png", 1);
	addTextureToMap(Hats, "hats/bucket hat.png", 1);
	addTextureToMap(Hats, "hats/cap.png", 1);
	addTextureToMap(Hats, "hats/top hat.png", 1);
	// extras 
	addTextureToMap(Extras, "extras/NONE.png", 30); // high chance to have no extras
	addTextureToMap(Extras, "extras/glasses.png", 9);
	addTextureToMap(Extras, "extras/overalls.png", 1); // super rare mario overalls.  

	PrefabRegistry* pref = PrefabRegistry::get();
	//person object.
	person_obj = pref->InstantiatePrefab("P_Renderable_Object");
	game_object->addChild(person_obj);
	person_obj->setName("person");
	person_obj->getTransform()->setLocalZheight(1);

	//clothes object.
	clothes_obj = pref->InstantiatePrefab("P_Renderable_Object");
	game_object->addChild(clothes_obj);
	clothes_obj->setName("clothes");
	clothes_obj->getTransform()->setLocalZheight(1.1);

	//hair object.
	hair_obj = pref->InstantiatePrefab("P_Renderable_Object");
	game_object->addChild(hair_obj);
	hair_obj->setName("hair");
	hair_obj->getTransform()->setLocalZheight(1.5);

	//facial_hair object.
	facial_hair_obj = pref->InstantiatePrefab("P_Renderable_Object");
	game_object->addChild(facial_hair_obj);
	facial_hair_obj->setName("facial_hair");
	facial_hair_obj->getTransform()->setLocalZheight(1.2);

	//hats object.
	hats_obj = pref->InstantiatePrefab("P_Renderable_Object");
	game_object->addChild(hats_obj);
	hats_obj->setName("hat");
	hats_obj->getTransform()->setLocalZheight(1.6);

	//extras object.
	extras_obj = pref->InstantiatePrefab("P_Renderable_Object");
	game_object->addChild(extras_obj);
	extras_obj->setName("extras");
	extras_obj->getTransform()->setLocalZheight(1.4);

	//eyes object. 
	eyes_obj = pref->InstantiatePrefab("P_Renderable_Object");
	game_object->addChild(eyes_obj);
	eyes_obj->setName("eyes");
	eyes_obj->getTransform()->setLocalZheight(1.3);
}

// actually create the character.
void S_CharactorCreator::createCharacter()
{
	// Get children and set their texture from a random, weighted texture from the corresponding asset database array

	person_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Person));

	clothes_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Clothes));

	hair_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Hair));

	facial_hair_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(FacialHair));

	hats_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Hats));

	extras_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Extras));

	eyes_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Eyes));
}

// returns false if notable changes have been made (wont be accepted). (should be just under 50% of the time)
bool S_CharactorCreator::createSimilarCharacter()
{
	// always change hats and clothes (the actual challenge)
	hats_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Hats));

	clothes_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Clothes));

	// change a distinct feature (person, eyes, beard, hair)

	int changable_object_count = 4; 
	currentCharacter old_character = current_character;
	int fallback_count = changable_object_count; // fallback count so it cant run forever if it gets extremely lucky 

	// 50% chance to change 1 thing, 50% after that to change a second ect...
	while (((double)rand()) / RAND_MAX < change_distinct_features && fallback_count > 0) {
		switch (rand() % changable_object_count) {
		case 0:
			person_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Person));
		case 1:
			eyes_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Eyes));
		case 2:
			facial_hair_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(FacialHair));
		case 3:
			hair_obj->getComponent<Texture>()->setTexture(getRandomTextureFromkey(Hair));
		}
		fallback_count--; // decrement fallback count to limit amount of changes. 
	}

	// check if the character changed (have to do this way bc choosing a new object could re-generate the same old one. 
	// if I had thought about my code before coding theres probably a better way to do all of this, but oh well. 
	// might come back and re-write later, but it works perfectly (i hope) code is just ugly
	if (old_character.eyes != current_character.eyes)
		return 0;
	else if (old_character.facial_hair != current_character.facial_hair)
		return 0;
	else if (old_character.hair != current_character.hair)
		return 0;
	else if (old_character.person != current_character.person)
		return 0;

	return 1; // would be similar to accept 
}

std::vector<GameObject*> S_CharactorCreator::getCurrentCharacter()
{
	return game_object->getChilderen();
}

sf::Texture* S_CharactorCreator::getRandomTextureFromkey(categories category)
{
	std::vector<std::pair<sf::Texture*, float>>array = asset_database[category];

	// define pair for return value.
	std::pair<sf::Texture*, int> returnval;
	returnval.first = nullptr;
	returnval.second = -1;

	// Calculate total weight
	float total_weight = 0.0f;
	for (std::pair<sf::Texture*, float> pair : array)
		total_weight += pair.second;

	// generate random value
	float random_value = static_cast<float>(rand()) / RAND_MAX * total_weight;

	// Select based on weighted probability
	float cumulative = 0.0f;
	int count = 0;
	for (const auto& pair : array) {
		cumulative += pair.second;
		if (random_value <= cumulative) {
			switch (category) {
			case Person:
				current_character.person = count;
			case Clothes:
				current_character.clothes = count;
			case Hair:
				current_character.hair= count;
			case FacialHair:
				current_character.facial_hair = count;
			case Hats:
				current_character.hats = count;
			case Extras:
				current_character.extras = count;
			case Eyes:
				current_character.eyes = count;
			}
			return pair.first;
		}
		count++;
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