#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_CharactorCreator.h"

REGISTER_PREFAB(
	P_Character_Creator,            // name
	[]() -> GameObject* // lambda construction func
	{

		PrefabRegistry* pref = PrefabRegistry::get();		
		GameObject* game_object = new GameObject("Character_Creator");
		game_object->addScript<S_CharactorCreator>();

		//person object.
		GameObject* person = pref->InstantiatePrefab("P_Renderable_Object");
		game_object->addChild(person);
		person->setName("person");
		person->getTransform()->setLocalZheight(1);

		//clothes object.
		GameObject* clothes = pref->InstantiatePrefab("P_Renderable_Object");
		game_object->addChild(clothes);
		clothes->setName("clothes");
		clothes->getTransform()->setLocalZheight(1.1);

		//hair object.
		GameObject* hair = pref->InstantiatePrefab("P_Renderable_Object");
		game_object->addChild(hair);
		hair->setName("hair");
		hair->getTransform()->setLocalZheight(1.4);

		//facial_hair object.
		GameObject* facial_hair = pref->InstantiatePrefab("P_Renderable_Object");
		game_object->addChild(facial_hair);
		facial_hair->setName("facial_hair");
		facial_hair->getTransform()->setLocalZheight(1.2);

		//hats object.
		GameObject* hat = pref->InstantiatePrefab("P_Renderable_Object");
		game_object->addChild(hat);
		hat->setName("hat");
		hat->getTransform()->setLocalZheight(1.5);

		//extras object.
		GameObject* extras = pref->InstantiatePrefab("P_Renderable_Object");
		game_object->addChild(extras);
		extras->setName("extras");
		extras->getTransform()->setLocalZheight(1.3);

		////eyes object. (unused, but might be used later).  (just adding 2 eyes will add ~30k new possible people.
		//GameObject* eyes = pref->InstantiatePrefab("P_Renderable_Object");
		//game_object->addChild(eyes);
		//eyes->setName("eyes");

		return game_object;
	});