#include "../GameObject.h"
#include "../Components/Transform.h"
#include "../ComponentInterfaces.h"
#include "../Systems/GameSystem.h"


GameObject::GameObject(std::string _name)
{
	transform.setGameObject(this);
	name = _name;
}

GameObject::~GameObject()
{
	
}

// update physics with given timestep (affects all children aswell)
void GameObject::physicsUpdate(float timestep)
{
	if (is_active) {
		for (auto& comp : components) {
			IPhysicsObject* physics = dynamic_cast<IPhysicsObject*>(comp);
			if (physics) {
				physics->physicsUpdate(timestep);
				//return; // TODO: ONLY DO ON HIGHEST IN HEIRARCHY WITH A PHYSICS OBJECT OR ISSUES MAY HAPPEN <-- it does but easy to avoid so leaving in because funny stuff may be posisble with it...
			}
		}
		// call on all childeren
		for (GameObject* child : childeren) {
			child->physicsUpdate(timestep);
		}
	}
}

void GameObject::fixedUpdate(float timestep)
{
	if (is_active) {
		for (auto& comp : components) {
			IScriptableBehaviour* scriptable = dynamic_cast<IScriptableBehaviour*>(comp);
			if (scriptable) {
				scriptable->fixedUpdate(timestep);
			}
		}
		// call on all childeren
		for (GameObject* child : childeren) {
			child->fixedUpdate(timestep);
		}
	}
}

void GameObject::update(float dt)
{
	if (is_active) {
		for (IComponent* comp : components) {
			comp->update(dt);
		}
		// call on all childeren
		for (GameObject* child : childeren) {
			child->update(dt);
		}
	}
}

void GameObject::lateUpdate(float dt)
{
	if (is_active) {
		for (IComponent* comp : components) {
			comp->lateUpdate(dt);
		}
		// call on all childeren
		for (GameObject* child : childeren) {
			child->lateUpdate(dt);
		}
	}
}

std::vector<IRenderable*> GameObject::render()
{
	std::vector<IRenderable*> result;
	if (is_drawn) {
		for (auto& comp : components) {
			IRenderable* renderable = dynamic_cast<IRenderable*>(comp);
			if (renderable) {
				result.push_back(renderable);
			}
		}
		// call on all childeren
		for (GameObject* child : childeren) {
			std::vector<IRenderable*> childRenderables = child->render();
			result.insert(result.end(), childRenderables.begin(), childRenderables.end());
		}
	}
	return result;
}

void GameObject::destroy()
{
	GameSystem::get()->addToDestroyQueue(this);
	pending_destroy = true;
}


GameObject* GameObject::addChild(GameObject* _game_ob)
{
	childeren.push_back(_game_ob);
	_game_ob->setParent(this);
	return _game_ob;
}

bool GameObject::isActive()
{
	return is_active;
}

void GameObject::setActive(bool val)
{
	// if val is different to what is currently, call onEnable or disable
	if (val != is_active)
	{
		if (val) {
			for (IComponent* comp : components) {
				comp->onEnable();
			}
		}
		else {
			for (IComponent* comp : components) {
				comp->onDisable();
			}
		}
	}
}

bool GameObject::isDrawn()
{
	return is_drawn;
}

void GameObject::setDrawn(bool val)
{
	is_drawn = val;
}

std::vector<IComponent*> GameObject::getAllComponents()
{
	return components;
}

// returns all children, including childeren of childeren. 
std::vector<GameObject*> GameObject::getAllChilderen()
{
	std::vector<GameObject*> result;

	for (GameObject* child : childeren) {
		result.push_back(child);

		// get all children from the child.
		std::vector<GameObject*> sub_children = child->getAllChilderen();
		result.insert(result.end(), sub_children.begin(), sub_children.end());
	}

	// return up the chain
	return result;
}

Transform* GameObject::getTransform()
{
	return &transform;
}

// returns all children attatched to the gameObject
std::vector<GameObject*>& GameObject::getChilderen()
{
	return childeren;
}

// gets the first child with the name specified
GameObject* GameObject::getChildByName(std::string name)
{
	for (GameObject* child : childeren) {
		if (child->getName() == name)
			return child;
	}
	return nullptr;
}

GameObject* GameObject::getParent()
{
	return parent;
}

void GameObject::setParent(GameObject* _parent)
{
	parent = _parent;
}

std::string GameObject::getName()
{
	return name;
}

void GameObject::setName(std::string _name)
{
	name = _name;
}
