#pragma once
#include "IScriptableBehaviour.h"

class ScriptableTest : public IScriptableBehaviour
{
	// Physics stuff.
	virtual void onTriggerEnter(GameObject*); // Called when entering a
	// trigger.
	virtual void onTriggerStay(GameObject*);  // Called every frame inside a
	// trigger.
	virtual void onTriggerExit(GameObject*);  // Called when exiting a trigger.
	virtual void onCollision(GameObject*);    // Called when colliding with
	// another object.
// Clickable stuff.
	virtual void onClick();     // Called when this object is clicked
	virtual void onRelease();   // Called when mouse released on object
	virtual void onHover();     // Called when mouse hovers over object
	virtual void onStopHover(); // called once when mouse leaves collider
};