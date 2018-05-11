#include "Scene.h"

namespace BE
{
	Scene::Scene(std::string tag_) : tag(tag_)
	{
		objectManager.addObject(new Object("Shiny"));
	}
} //End namespace