#pragma once
#include "Scene.h"
#include <map>
#include "Exceptions.h"

namespace BE
{
	class SceneManager
	{
		std::map<std::string, std::shared_ptr<Scene>> sceneMap;


	public:
		//TODO Make placeholder scene
		SceneManager(std::shared_ptr<Scene> scn = std::make_shared<Scene>("PlaceHolderScene")) {

			addScene(scn);
			currentScene.reset(scn.get());
			currentScene->initScene();
		}
		~SceneManager()
		{
			currentScene.release();
			sceneMap.clear();
		}

		std::unique_ptr<Scene> currentScene;
		void addScene(std::shared_ptr<Scene> scn, bool overwrite = false);

		void changeScene(std::string str);

		unsigned int getSceneCount() { return sceneMap.size(); }



	};

}