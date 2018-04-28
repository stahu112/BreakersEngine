#include "ObjectManager.h"

void BE::ObjectManager::addObject(Object * obj)
{
	std::string append{ "1" };
	unsigned int i = 1;
	std::string buff{ obj->getTag() };

	while (tagTaken(obj->getTag()))
	{
		obj->setTag(buff + append);

		i++;
		append = std::to_string(i);
	}

	Logger::log("From: " + this->tag + " : add object with tag: " + obj->getTag());
	this->objectMap.insert(std::make_pair(obj->getTag(), obj));
}

void BE::ObjectManager::destroyAllObjects()
{
	auto beg = it_begin();
	auto end = it_end();

	while (beg != end)
	{
		delete beg->second;
		objectMap.erase(beg);
		beg++;
	}
	Logger::log("From : " + this->tag + " : destroyed all objects");
}

bool BE::ObjectManager::tagTaken(std::string tag_)
{
	if (objectMap.find(tag_) == objectMap.end())
	{
		return false;
	}
	else
	{
		Logger::log("From: " + this->tag + " :tag : " + tag_ + " : is already taken");
		return true;
	}
}