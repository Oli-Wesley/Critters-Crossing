#include "S_CharactorCreator.h"
#include "../Libraries/GameEngine.h"
#include <algorithm>
#include <random> 
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
	person_obj = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "person"));
	person_obj->getTransform()->setLocalZheight(1);

	//clothes object.
	clothes_obj = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "clothes"));
	clothes_obj->getTransform()->setLocalZheight(1.1);

	//hair object.
	hair_obj = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "hair"));
	hair_obj->getTransform()->setLocalZheight(1.5);

	//facial_hair object.
	facial_hair_obj = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "facial_hair"));
	facial_hair_obj->getTransform()->setLocalZheight(1.2);

	//hats object.
	hats_obj = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "hat"));
	hats_obj->getTransform()->setLocalZheight(1.6);

	//extras object.
	extras_obj = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "extras"));
	extras_obj->getTransform()->setLocalZheight(1.4);

	//eyes object. 
	eyes_obj = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "eyes"));
	eyes_obj->getTransform()->setLocalZheight(1.3);
}

void S_CharactorCreator::update(float dt)
{
	Transform* trans = game_object->getTransform();
	in_target_pos = 0;
	in_frame_pos = 0;
	// if close, set position to actual pos
	if ((trans->getLocalPosition() == target_pos) || (abs(trans->getLocalPosition().x - target_pos.x) < 3)) {
		trans->setLocalPosition(target_pos);
		in_target_pos = 1;
		if (target_pos.x == 25)
			in_frame_pos = 1;
	}
	if (trans->getLocalPosition().x < target_pos.x)
	{
		trans->move(movement_speed * dt, 0);
		
	}
	else if (trans->getLocalPosition().x > target_pos.x)
	{
		trans->move(-movement_speed * dt, 0);
	}

	// some goofy stuff to animate the character bobbing up and down 
	trans->setLocalPosition(trans->getGlobalPosition().x, 25 + (abs(sin(((trans->getGlobalPosition().x - 25) / 25)) * 10)));
}

// sets the target pos to move towards
void S_CharactorCreator::setTargetPos(int x_pos)
{
	target_pos = sf::Vector2f(x_pos * GameSystem::get()->getCurrentScene()->scene_root->getTransform()->getLocalScale().x, game_object->getTransform()->getLocalPosition().y);
	in_target_pos = 0;
}

void S_CharactorCreator::setMovementSpeed(float speed)
{
	movement_speed = speed;
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

	
	// array of objects and their corresponding key
	std::vector<std::pair<GameObject*, categories>> features = {
		{ person_obj, Person },
		{ eyes_obj, Eyes },
		{ facial_hair_obj, FacialHair },
		{ hair_obj, Hair }
	};

	// Keep old character snapshot
	currentCharacter old_character = current_character;

	// shuffle the list so a different feature gets changed first each time.
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(features.begin(), features.end(), g);
	float chance = 0.5;
	for (std::pair<GameObject*, categories> feature : features) {
		if (((double)rand() / RAND_MAX) < chance) {
			feature.first->getComponent<Texture>()->setTexture(getRandomTextureFromkey(feature.second));
			chance*=0.5; // decrease chance to change another texture. 
		}
	}

	// Check if any distinct feature changed
	if (old_character.person != current_character.person ||
		old_character.eyes != current_character.eyes ||
		old_character.facial_hair != current_character.facial_hair ||
		old_character.hair != current_character.hair)
	{
		return false; // notable change 
	}

	return true; // similar enough (only clothes/hat changed)
}

std::vector<GameObject*> S_CharactorCreator::getCurrentCharacter()
{
	return game_object->getChilderen();
}

sf::Texture* S_CharactorCreator::getRandomTextureFromkey(categories category)
{
	std::vector<std::pair<std::unique_ptr<sf::Texture>, float>>& array = asset_database[category];

	// Calculate total weight
	float total_weight = 0.0f;
	for (const std::pair<std::unique_ptr<sf::Texture>, float>& pair : array)
		total_weight += pair.second;

	if (total_weight <= 0.f) return nullptr;

	// generate random value
	float random_value = static_cast<float>(rand()) / RAND_MAX * total_weight;

	// Select based on weighted probability
	float cumulative = 0.0f;
	int count = 0;
	for (const auto& pair : array) {
		cumulative += pair.second;
		if (random_value <= cumulative) {
			switch (category) {
			case Person:      current_character.person = count; break;
			case Clothes:     current_character.clothes = count; break;
			case Hair:        current_character.hair = count; break;
			case FacialHair:  current_character.facial_hair = count; break;
			case Hats:        current_character.hats = count; break;
			case Extras:      current_character.extras = count; break;
			case Eyes:        current_character.eyes = count; break;
			}
			return pair.first.get();
		}
		count++;
	}
	//should never be called.
	return nullptr;
}

// map_key = catagory that it can be. 
bool S_CharactorCreator::addTextureToMap(categories map_key, std::string texture_path, float spawn_probability)
{
	std::unique_ptr<sf::Texture> tex = std::make_unique<sf::Texture>();
	if (tex->loadFromFile(relative_path + texture_path))
	{
		asset_database[map_key].emplace_back(std::move(tex), spawn_probability);
		return 1;
	}
	std::cout << "failed to load texture: " << relative_path + texture_path << std::endl;
	return 0;
}