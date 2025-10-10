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
	static PrefabRegistry* get();
	void RegisterPrefab(
		const std::string& name, std::function<GameObject* ()> constructor);
	GameObject* InstantiatePrefab(std::string name);
	GameObject* InstantiatePrefab(std::string name, sf::Vector2f position);
	GameObject* InstantiatePrefab(std::string name, float x, float y);

protected:
	PrefabRegistry() {}
	std::unordered_map<std::string, std::function<GameObject* ()>> prefabRegistry;

	static PrefabRegistry* instance;
	PrefabRegistry(PrefabRegistry const&) = delete;
	void operator=(PrefabRegistry const&) = delete;
};