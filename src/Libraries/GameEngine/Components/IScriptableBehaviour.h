#pragma once
#include "IComponent.h"
#include "../ScriptableBehaviour.h"

class IScriptableBehaviour : public IComponent {
private:
	// array of all scripts on a gameObject.
	std::vector<ScriptableBehaviour*> scripts;
public:
	virtual ~IScriptableBehaviour() {
		for (auto* s : scripts) {
			s->onDestroy();
			delete s;
		}
		scripts.clear();
	}

	void addScript(ScriptableBehaviour* script) {
		scripts.push_back(script);
		script->addGameObject(game_object);
		script->start();
	}

	// reuturns all scripts (probably useless)
	const std::vector<ScriptableBehaviour*>& getScripts() const { return scripts; };

	// all functions that are scriptable. 
    // Called when the component is enabled
	void onEnable() { for (auto* s : scripts) s->onEnable(); }
	// Called every frame
	void update(float dt) { for (auto* s : scripts) s->update(dt); }
	// called after update
	void lateUpdate(float dt) { for (auto* s : scripts) s->lateUpdate(dt); }
	// Called when the GameObject is disabled 
	void onDisable() { for (auto* s : scripts) s->onDisable(); }
	// Called when the component is destroyed
	void onDestroy() { for (auto* s : scripts) s->onDestroy(); }
	// called at fixed intervals. (physics tick)
	void fixedUpdate(float timestep) { for (auto* s : scripts) s->fixedUpdate(timestep); }

	// Physics stuff.
	// Called when entering a trigger.
	void onTriggerEnter(GameObject* obj) { for (auto* s : scripts) s->onTriggerEnter(obj); }
	// Called every frame inside a trigger.
	void onTriggerStay(GameObject* obj) { for (auto* s : scripts) s->onTriggerStay(obj); }
	// Called when exiting a trigger.
	void onTriggerExit(GameObject* obj) { for (auto* s : scripts) s->onTriggerExit(obj); }
	// Called when colliding with another object.
	void onCollision(GameObject* obj) { for (auto* s : scripts) s->onCollision(obj); }

	// Clickable stuff (needs clickable component)
	// Called when this object is clicked
	void onClick() { for (auto* s : scripts) s->onClick(); }
	// Called when mouse released on object
	void onRelease() { for (auto* s : scripts) s->onRelease(); }
	// Called when mouse hovers over object
	void onHover() { for (auto* s : scripts) s->onHover(); }
	// called once when mouse leaves collider
	void onStopHover() { for (auto* s : scripts) s->onStopHover(); }
};
