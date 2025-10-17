#pragma once

#pragma once
#include "../Libraries/GameEngine.h"
#include "../Scripts/S_AcceptDeny.h"
#include "../Scripts/S_Passport.h"

REGISTER_PREFAB(
	P_Passport,            // name
	[]() -> GameObject* // lambda construction func
	{
		PrefabRegistry* pref = PrefabRegistry::get();
		GameObject* game_object = new GameObject("Passport");
		game_object->getTransform()->setLocalScale(4, 4);

		GameObject* passport_background = game_object->addChild(pref->InstantiatePrefab("P_Renderable_Object"));
		GameObject* passport_foreground = game_object->addChild(pref->InstantiatePrefab("P_Renderable_Object"));
		GameObject* passport_person = game_object->addChild(pref->InstantiatePrefab("P_Renderable_Object"));
		GameObject* passport_accept_deny = game_object->addChild(pref->InstantiatePrefab("P_Renderable_Object"));

		//person object.
		GameObject* person_obj = pref->InstantiatePrefab("P_Renderable_Object");
		passport_person->addChild(person_obj);
		person_obj->setName("person");
		person_obj->getTransform()->setLocalZheight(1);

		//clothes object.
		GameObject* clothes_obj = pref->InstantiatePrefab("P_Renderable_Object");
		passport_person->addChild(clothes_obj);
		clothes_obj->setName("clothes");
		clothes_obj->getTransform()->setLocalZheight(1.1);

		//hair object.
		GameObject* hair_obj = pref->InstantiatePrefab("P_Renderable_Object");
		passport_person->addChild(hair_obj);
		hair_obj->setName("hair");
		hair_obj->getTransform()->setLocalZheight(1.5);

		//facial_hair object.
		GameObject* facial_hair_obj = pref->InstantiatePrefab("P_Renderable_Object");
		passport_person->addChild(facial_hair_obj);
		facial_hair_obj->setName("facial_hair");
		facial_hair_obj->getTransform()->setLocalZheight(1.2);

		//hats object.
		GameObject* hats_obj = pref->InstantiatePrefab("P_Renderable_Object");
		passport_person->addChild(hats_obj);
		hats_obj->setName("hat");
		hats_obj->getTransform()->setLocalZheight(1.6);

		//extras object.
		GameObject* extras_obj = pref->InstantiatePrefab("P_Renderable_Object");
		passport_person->addChild(extras_obj);
		extras_obj->setName("extras");
		extras_obj->getTransform()->setLocalZheight(1.4);

		//eyes object. 
		GameObject* eyes_obj = pref->InstantiatePrefab("P_Renderable_Object");
		passport_person->addChild(eyes_obj);
		eyes_obj->setName("eyes");
		eyes_obj->getTransform()->setLocalZheight(1.3);

		passport_background->setName("passport_background");
		passport_foreground->setName("passport_foreground");
		passport_person->setName("passport_person");
		passport_accept_deny->setName("passport_accept_deny");

		passport_person->getTransform()->setLocalScale(0.5, 0.5); // scale down so person fits.
		passport_person->getTransform()->setLocalPosition(6, 67); // set position of the person on the passport.
		
		passport_background->getTransform()->setLocalZheight(1);
		passport_person->getTransform()->setLocalZheight(1.1);
		passport_foreground->getTransform()->setLocalZheight(2.5); // big jump to let the person layers fit.
		passport_accept_deny->getTransform()->setLocalZheight(2.6);


		passport_background->getComponent<Texture>()->setTexture("../Data/Images/PassportLayers/Passport_background.png");
		passport_foreground->getComponent<Texture>()->setTexture("../Data/Images/PassportLayers/Passport_layer.png");
		passport_accept_deny->addScript<S_AcceptDeny>();

		game_object->addScript<S_Passport>();

		return game_object;
	});