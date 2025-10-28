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
		game_object->getTransform()->setLocalScale(3);
		game_object->getTransform()->setLocalZheight(3);

		GameObject* passport_background = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "passport_background"));
		GameObject* passport_foreground = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "passport_foreground"));
		GameObject* passport_person = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "passport_person"));
		GameObject* passport_accept_deny = game_object->addChild(pref->InstantiatePrefab("P_RenderableObject", "passport_accept_deny"));

		//person object.
		GameObject* person_obj = pref->InstantiatePrefab("P_RenderableObject", "person");
		passport_person->addChild(person_obj);
		person_obj->getTransform()->setLocalZheight(1);

		//clothes object.
		GameObject* clothes_obj = pref->InstantiatePrefab("P_RenderableObject", "clothes");
		passport_person->addChild(clothes_obj);
		clothes_obj->getTransform()->setLocalZheight(1.1);

		//hair object.
		GameObject* hair_obj = pref->InstantiatePrefab("P_RenderableObject", "hair");
		passport_person->addChild(hair_obj);
		hair_obj->getTransform()->setLocalZheight(1.5);

		//facial_hair object.
		GameObject* facial_hair_obj = pref->InstantiatePrefab("P_RenderableObject", "facial_hair");
		passport_person->addChild(facial_hair_obj);
		facial_hair_obj->getTransform()->setLocalZheight(1.2);

		//hats object.
		GameObject* hats_obj = pref->InstantiatePrefab("P_RenderableObject", "hat");
		passport_person->addChild(hats_obj);
		hats_obj->getTransform()->setLocalZheight(1.6);

		//extras object.
		GameObject* extras_obj = pref->InstantiatePrefab("P_RenderableObject", "extras");
		passport_person->addChild(extras_obj);
		extras_obj->getTransform()->setLocalZheight(1.4);

		//eyes object. 
		GameObject* eyes_obj = pref->InstantiatePrefab("P_RenderableObject", "eyes");
		passport_person->addChild(eyes_obj);
		eyes_obj->getTransform()->setLocalZheight(1.3);

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

		GameObject* trigger_vol = game_object->addChild(pref->InstantiatePrefab("P_TriggerVolume", "Passport Trigger", 12, 13));
		trigger_vol->getComponent<BoxCollider>()->setSize(66, 33);

		game_object->setDrawn(0);

		return game_object;
	});