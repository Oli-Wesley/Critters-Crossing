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

void Scene::onWindowResize(sf::Vector2i new_size)
{
	// Calculate scale 
	float scale_x = float(new_size.x) / target_resolution.x;
	float scale_y = float(new_size.y) / target_resolution.y;
	float uniform_scale = std::min(scale_x, scale_y);

	// apply scale
	scene_root->getTransform()->setLocalScale(uniform_scale, uniform_scale);
	dont_destroy->getTransform()->setLocalScale(uniform_scale, uniform_scale);

	// Calculate position to center the scene
	float offset_x = (new_size.x - target_resolution.x * uniform_scale) / 2.f;
	float offset_y = (new_size.y - target_resolution.y * uniform_scale) / 2.f;

	scene_root->getTransform()->setLocalPosition(offset_x, offset_y);
	dont_destroy->getTransform()->setLocalPosition(offset_x, offset_y);
}
