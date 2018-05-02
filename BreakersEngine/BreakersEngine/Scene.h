#pragma once
#include "ObjectManager.h"
#include <memory>

namespace BE
{
	class Scene
	{
		std::string tag{ "New scene" };

	public:
		std::string getTag() { return tag; }
		std::unique_ptr<ObjectManager> objectManager;

		virtual void initScene() { Logger::log(tag + " Init"); }
		virtual void onChangeScene() { Logger::log(tag + " SceneChange"); }

		Scene(std::string tag_) : tag(tag_) { objectManager = std::make_unique<ObjectManager>(this->tag + "-ObjectManager"); }
		~Scene() { Logger::log(tag + " destroyed"); }


	};

} //End namespace BE