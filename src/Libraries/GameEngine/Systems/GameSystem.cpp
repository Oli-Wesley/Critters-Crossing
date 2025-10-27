#include "GameSystem.h"
#include "../Scene.h"
#include "PhysicsSystem.h"

// Define the static member variable
GameSystem* GameSystem::instance = nullptr;

GameSystem* GameSystem::get()
{
	if (instance == nullptr)
	{
		instance = new GameSystem();
	}
	return instance;
}

void GameSystem::start()
{
	window = new sf::RenderWindow(resolution, window_title);
	window->setFramerateLimit(framerate);

	clock.restart();

	while (window->isOpen())
	{
		sf::Event e;
		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window->close();
		}
		runGameLoop(clock.restart().asSeconds()); // pass time since last frame as
		// dt to the current gameLoop.
	}
}

void GameSystem::start(std::string start_scene)
{
	switchScene(start_scene); // change target scene.
	changeScene();            // actually change into the scene.
	start(); // call the other start function that contains the gameLoop.
}

void GameSystem::addScene(Scene* scene, std::string scene_name)
{
	scenes.emplace(scene_name, scene);
}

void GameSystem::switchScene(std::string scene_name)
{
	if (scenes[scene_name])
		target_scene = scene_name;
	else
		std::cout << "SCENE DOES NOT EXIST, FAILED TO LOAD SCENE. '" << scene_name
		<< "'\n";
}

void GameSystem::Remove(std::string scene_name)
{
	scenes.erase(scene_name);
}

GameObject* GameSystem::findGameObject(std::string _id)
{
	return nullptr;
}

void GameSystem::runGameLoop(float dt)
{
	fixedUpdate(dt); // physics called in here aswell.
	update(dt);
	lateUpdate(dt);
	render();
	changeScene();
}

void GameSystem::setTitle(std::string _title)
{
	window_title = _title;
	if (window != nullptr)
		window->setTitle(_title);
}

void GameSystem::setResolution(sf::Vector2i res)
{
	resolution = sf::VideoMode(res.x, res.y);
	if (window != nullptr)
		window->setSize(sf::Vector2u(resolution.width, resolution.height));
}

void GameSystem::setResolution(int x, int y)
{
	setResolution(sf::Vector2(x, y));
}

void GameSystem::setFramerate(float _framerate)
{
	framerate = _framerate;
	if (window != nullptr)
		window->setFramerateLimit(framerate);
}

void GameSystem::setPhysicsTimestep(float tickspersecond)
{
	physics_timestep = 1.0f / tickspersecond;
}

bool GameSystem::isDebug()
{
	return is_debug;
}

void GameSystem::setDebug(bool flag)
{
	is_debug = flag;
}

sf::RenderWindow* GameSystem::getWindow()
{
	return window;
}

void GameSystem::runPhysics(float timestep)
{
	if (currentScene != nullptr)
	{
		currentScene->scene_root->physicsUpdate(timestep);
		PhysiscsSystem::get()->handleCollisions(
			currentScene->scene_root->getAllChilderenWithComponent<BoxCollider>());
	}
}

// thanks https://gafferongames.com/post/fix_your_timestep/
void GameSystem::fixedUpdate(float dt)
{
	// Clamp to limit timestep if something goes very wrong...
	const float maxDeltaTime = 0.25f;
	dt = std::min(dt, maxDeltaTime);

	accumulator += dt;

	// this allows for multiple physics ticks to be ran in a single frame, or none
	// at all if it's not needed.
	while (accumulator >= physics_timestep)
	{
		runPhysics(physics_timestep);
		if (currentScene && currentScene->scene_root)
		{
			currentScene->scene_root->fixedUpdate(physics_timestep);
		}
		accumulator -= physics_timestep;
	}
}

void GameSystem::update(float dt)
{
	if (currentScene != nullptr)
		currentScene->scene_root->update(dt);
}

void GameSystem::lateUpdate(float dt)
{
	if (currentScene != nullptr)
		currentScene->scene_root->lateUpdate(dt);
}

void GameSystem::render()
{
	if (currentScene != nullptr)
	{
		window->clear(currentScene->get_scene_color());
		std::vector<IRenderable*> renderables = currentScene->scene_root->render();
		// simple bubble sort, sort the list based on layer. (kinda slow but its fast enough for this..)
		bool changed = 1;
		IRenderable* hold;
		int length = renderables.size();

		while (changed)
		{
			changed = 0;
			for (int index = 0; index < length - 1; index++)
			{
				if (
					renderables[index]->getRenderOrder() >
					renderables[index + 1]->getRenderOrder())
				{
					hold = renderables[index];
					renderables[index] = renderables[index + 1];
					renderables[index + 1] = hold;
					changed = 1;
				}
			}
		}
		// render now sorted list
		for (IRenderable* var : renderables)
		{
			var->render(window);
		}
	}
	else
		window->clear(sf::Color::White); // still clear screen to white if the scene is nullptr
	window->display();
}

void GameSystem::changeScene()
{
	if (scenes[target_scene] != currentScene)
	{
		GameObject* dont_destroy = nullptr;
		if (currentScene != nullptr)
			dont_destroy = currentScene->unload();
		currentScene = scenes[target_scene];
		if (currentScene)
			currentScene->load(dont_destroy);
		else
			std::cout << "FAILED TO LOAD SCENE, SCENE EXISTS BUT RETURNS NULLPTR";
	}
}