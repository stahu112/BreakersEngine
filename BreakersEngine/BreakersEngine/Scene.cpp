#include "Scene.h"

namespace BE
{
	Scene::Scene(std::string tag_) : tag(tag_)
	{
		objectManager = std::make_unique<ObjectManager>(this->tag + "-ObjectManager");
	}
} //End namespace