#pragma once
#include "ObjectManager.h"
#include <memory>
#include "SceneState.h"

namespace BE
{
	class Scene
	{
		std::string tag{ "New scene" };

		SceneStateMachine stateMachine{ std::unique_ptr<Scene>(this), std::make_unique<SceneState>() };

	public:
		std::string getTag() { return tag; }
		std::unique_ptr<ObjectManager> objectManager;

		virtual void initScene() { Logger::log(tag + " Init"); }
		virtual void onChangeScene() { Logger::log(tag + " SceneChange"); }

		Scene(std::string tag_);
		~Scene() {
			Logger::log(tag + " destroyed");
		}


	};

} //End namespace BE