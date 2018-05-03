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
	this->objectMap.at(obj->getTag())->onInit();
}

void BE::ObjectManager::callUpdate()
{
	for (auto &x : objectMap)
	{
		x.second->update();
	}
}

void BE::ObjectManager::callLateUpdate()
{
	for (auto &x : objectMap)
	{
		x.second->lateUpdate();
	}
}

BE::Object * BE::ObjectManager::getObjectByTag(std::string tag_)
{
	if (objectMap.find(tag_) != objectMap.end())
	{
		Logger::log("From: " + this->tag + ": Get by tag: " + tag_);
		return objectMap.at(tag_);
	}
	else
	{
		Logger::log("From: " + this->tag + ": no object with tag: " + tag_);
		throw Exceptions::EXObjectWithTagNotFound{};
	}
}

void BE::ObjectManager::destroyObjectByTag(std::string tag_) {
	delete objectMap.at(tag_);
	objectMap.erase(tag_);
}

unsigned int BE::ObjectManager::objectCount() const {
	Logger::log("Object count of: " + this->tag + " = " + std::to_string(objectMap.size()));
	return objectMap.size();
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
	Logger::log("From: " + this->tag + ": destroyed all objects");
}

bool BE::ObjectManager::tagTaken(std::string tag_)
{
	if (objectMap.find(tag_) == objectMap.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}