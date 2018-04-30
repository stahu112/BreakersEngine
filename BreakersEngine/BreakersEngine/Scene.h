#pragma once
#include "ObjectManager.h"
#include <memory>

namespace BE
{
	class Scene
	{
		std::string tag{ "New scene" };

	public:

		std::unique_ptr<ObjectManager> objectManager;

		Scene(std::string tag_) : tag(tag_) { objectManager = std::make_unique<ObjectManager>(this->tag + "-ObjectManager"); }
		~Scene() {}


	};

} //End namespace BE