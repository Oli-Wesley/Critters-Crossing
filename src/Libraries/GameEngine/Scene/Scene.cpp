#include "../Scene.h"
#include "../GameObject.h"

Scene::Scene()
{
	dont_destroy = nullptr;
}

Scene::~Scene()
{
	scene_root->destroy();
}

GameObject* Scene::unload()
{
	onUnload(); // call each scene's onUnload functions.
	scene_root->destroy();
	return dont_destroy;
}

void Scene::load(GameObject* _dont_destroy)
{
	scene_root = new GameObject("Scene_Root"); // create scene root.
	// call each scene's individual load function.
	if (_dont_destroy == nullptr) {
		dont_destroy = new GameObject("Dont_Destroy");
	}
	else {
		dont_destroy = _dont_destroy;
	}
	load();
}
