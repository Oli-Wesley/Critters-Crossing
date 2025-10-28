#pragma once

#include "../gameObject.h"
#include <functional>
#include <string>
#include <unordered_map>

// Register Prefab macro, individual prefabs can use this to add themselves to
// the prefabRegistry.
#define REGISTER_PREFAB(name, func)                     \
  static bool name##_registered = []()                  \
  {                                                     \
    PrefabRegistry::get()->RegisterPrefab(#name, func); \
    return true;                                        \
  }()

class PrefabRegistry
{
public:
	// get a pointer to the prefab registry singleton instance
	static PrefabRegistry* get();
	// register prefabs to the prefab registry map to be loaded elsewhere. 
	void RegisterPrefab(
		const std::string& name, std::function<GameObject* ()> constructor);

	// instantiate prefab with given name 
	GameObject* InstantiatePrefab(std::string name);
	// instantiate prefab with given name at coords specified
	GameObject* InstantiatePrefab(std::string name, sf::Vector2f position);
	// instantiate prefab with given name at coords specified
	GameObject* InstantiatePrefab(std::string name, float x, float y);

	// instantiate prefab with given name and override the name on the gameObject.
	GameObject* InstantiatePrefab(std::string name, std::string new_name);
	// instantiate prefab with given name at coords specified and override the name on the gameObject.
	GameObject* InstantiatePrefab(std::string name, std::string new_name, sf::Vector2f position);
	// instantiate prefab with given name at coords specified and override the name on the gameObject.
	GameObject* InstantiatePrefab(std::string name, std::string new_name, float x, float y);

protected:
	PrefabRegistry() {}
	std::unordered_map<std::string, std::function<GameObject* ()>> prefabRegistry;

	static PrefabRegistry* instance;
	PrefabRegistry(PrefabRegistry const&) = delete;
	void operator=(PrefabRegistry const&) = delete;
};