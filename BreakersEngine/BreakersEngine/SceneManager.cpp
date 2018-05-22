#include "SceneManager.h"
#include "PlaceHolderScene.h"

//TODO SPLASH SCENE
BE::SceneManager::SceneManager() {
	std::shared_ptr<Scene> scn = std::make_shared<Scene>();
	addScene(scn);
	addScene(std::make_shared<PlaceHolderScene>());
	currentScene.reset(scn.get());
}

void BE::SceneManager::addScene(std::shared_ptr<Scene> scn, bool overwrite) {

	if (sceneMap.find(scn->getTag()) == sceneMap.end())
	{
		sceneMap.insert(std::make_pair(scn->getTag(), scn));
	}
	else
	{
		if (!overwrite)
		{
			Logger::log("There's already a scene with tag: " + scn->getTag() + " in the scene pool");
		}
		else
		{
			sceneMap.at(scn->getTag()).reset(scn.get());
			Logger::log("Overwritten " + scn->getTag() + " scene");
		}
	}
}

void BE::SceneManager::changeScene(std::string str)
{
	if (sceneMap.find(str) == sceneMap.end())
	{
		Logger::log("There's no scene with name: " + str + " in the manager");
		throw Exceptions::EXSceneWithNameNotFound{};
	}
	else
	{
		currentScene->onChangeScene();
		currentScene.release();
		currentScene.reset(sceneMap.at(str).get());
		currentScene->initScene();
	}
}
