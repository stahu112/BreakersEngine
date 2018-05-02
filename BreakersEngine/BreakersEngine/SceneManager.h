#pragma once
#include "Scene.h"
#include <map>
#include "Exceptions.h"

namespace BE
{
	class SceneManager
	{
		std::map<std::string, Scene*> sceneMap;

		Scene* currentScene;

	public:
		//TODO Make placeholder scene
		SceneManager(Scene* scn = new BE::Scene("PlaceHolderScene")) : currentScene(scn) {
			addScene(scn);
			currentScene->initScene();
		}
		~SceneManager()
		{
			for (auto x : sceneMap)
			{
				delete x.second;
			}
		}

		void addScene(Scene* scn, bool overwrite = false);
		void changeScene(std::string str);

		unsigned int getSceneCount() { return sceneMap.size(); }

		Scene* getCurrentScene() { return currentScene; }

	};

}