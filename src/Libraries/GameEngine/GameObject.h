#pragma once
#include <vector>
#include <typeindex>
#include "Components/IComponent.h"  
#include "Components/IRenderable.h"  
#include "Components/Transform.h"
#include "Components/IScriptableBehaviour.h"

class GameObject {
public:
	GameObject(std::string _name);
	~GameObject();
	// lifecycle events
	void fixedUpdate(float timestep);
	void physicsUpdate(float timestep);
	void update(float dt);
	void lateUpdate(float dt);
	std::vector<IRenderable*> render();
	void destroy();
	void destroy(bool destroy_children);


	// Template functions so have to go here bc I dont understand how to make them work elsewhere...

	// usage: addComponent<ComponentType>(args)  CONSTRUCTOR OF THE COMPONENT MUST HAVE CORRESPONDING ARGUMENTS. ;
	template<typename T, typename... Args>
	T* addComponent(Args&&... args) {
		static_assert(std::is_base_of<IComponent, T>::value, "T must derive from Component");

		// Check if component already exists
		for (IComponent* comp : components) {
			if (T* existing = dynamic_cast<T*>(comp)) {
				throw std::runtime_error("Cannot Have 2 components of same type");
			}
		}

		// Create and add new component
		T* newC = new T(std::forward<Args>(args)...);
		newC->setGameObject(this);
		newC->start();
		components.push_back(newC);
		return newC;
	}

	// returns the component on this gameObject with type.
	template<typename T>
	T* getComponent() {
		if constexpr (std::is_base_of_v<IComponent, T>) {
			for (IComponent* comp : components) {
				if (auto casted = dynamic_cast<T*>(comp))
					return casted;
			}

			// special case for transform as it isnt in the components list (best to use getTransform)
			if constexpr (std::is_same_v<T, Transform>)
				return getTransform();
		}
		// case to get scripts from the scriptable behaviour. 
		else
		{
			IScriptableBehaviour* iscript = getComponent<IScriptableBehaviour>();
			if (iscript) {
				return iscript->getScript<T>();
			}
		}
		return nullptr;
	}

	template<typename T>
	std::vector<GameObject*> getAllChilderenWithComponent() {
		std::vector<GameObject*> all_children = getAllChilderen();

		// remove elements from the list that do not have the asked for component.
		for (int i = 0; i < all_children.size(); i++) {
			if (!all_children[i]->hasComponent<T>()) {
				all_children.erase(all_children.begin() + i);
			}
		}
		return all_children;
	}

	// returns the component on this gameObject with type.
	template<typename T>
	bool hasComponent() {
		for (IComponent* comp : components) {
			if (auto casted = dynamic_cast<T*>(comp))
				return true;
		}
		false;
	}

	// attatch a script to the gameObject
	template<typename T, typename... Args>
	T* addScript(Args&&... args) {
		static_assert(std::is_base_of<ScriptableBehaviour, T>::value,
			"T must derive from ScriptableBehaviour");

		// Check if the GameObject already has a Scriptable interface
		IScriptableBehaviour* script_interface = nullptr;
		for (IComponent* comp : components) {
			script_interface = dynamic_cast<IScriptableBehaviour*>(comp);
			if (script_interface) break;
		}

		// If not found, add one
		if (!script_interface) {
			script_interface = addComponent<IScriptableBehaviour>();
		}

		// Create the new script
		T* new_script = new T(std::forward<Args>(args)...);

		// Add it to the script interface
		script_interface->addScript(new_script);

		return new_script;
	}

	GameObject* addChild(GameObject* _game_obj);

	bool isActive();
	void setActive(bool);
	std::vector<IComponent*> getAllComponents();

	// get all children (including childeren of childeren)
	std::vector<GameObject*> getAllChilderen();

	Transform* getTransform();
	std::vector<GameObject*> getChilderen();
	GameObject* getChildByName(std::string name);
	GameObject* getParent();
	void setParent(GameObject*);

	std::string getName();
	void setName(std::string _name);

protected:
	std::string name;
	std::vector<IComponent*> components;
	bool is_active = true;
	std::vector<GameObject*> childeren;
	Transform transform;
	GameObject* parent = nullptr;
};