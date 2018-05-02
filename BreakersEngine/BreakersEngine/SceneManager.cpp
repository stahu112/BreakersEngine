#include "SceneManager.h"

void BE::SceneManager::addScene(Scene * scn, bool overwrite) {

	if (sceneMap.find(scn->getTag()) == sceneMap.end())
	{
		Logger::log("Added " + scn->getTag() + " scene to the scenePool");
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
			delete sceneMap.at(scn->getTag());
			sceneMap.at(scn->getTag()) = scn;
			Logger::log("Overwrited " + scn->getTag() + " scene");
		}
	}
}

void BE::SceneManager::changeScene(std::string str)
{
	if (sceneMap.find(str) == sceneMap.end())
	{
		Logger::log("There's no scene with name: " + str + "i n the manager");
		throw Exceptions::EXSceneWithNameNotFound{};
	}
	else
	{
		currentScene->onChangeScene();
		currentScene = sceneMap.at(str);
		currentScene->initScene();
	}
}
