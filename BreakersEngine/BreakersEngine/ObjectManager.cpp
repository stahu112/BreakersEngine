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

	this->objectMap.insert(std::make_pair(obj->getTag(), obj));
	this->objectMap.at(obj->getTag())->onInit();
}

void BE::ObjectManager::callUpdate()
{
	for (auto &x : objectMap)
	{
		if (x.second->active) x.second->update();
	}
}

void BE::ObjectManager::callLateUpdate()
{
	for (auto &x : objectMap)
	{
		if (x.second->active) x.second->lateUpdate();
	}
}

BE::Object * BE::ObjectManager::getObjectByTag(std::string tag_)
{
	if (objectMap.find(tag_) != objectMap.end())
	{
		return objectMap.at(tag_);
	}
	else
	{
		throw Exceptions::EXObjectWithTagNotFound{};
	}
}

void BE::ObjectManager::destroyObjectByTag(std::string tag_) {
	delete objectMap.at(tag_);
	objectMap.erase(tag_);
}

unsigned int BE::ObjectManager::objectCount() const {
	return objectMap.size();
}

void BE::ObjectManager::showContents()
{

	Logger::log("\n===== Contents of " + this->tag + "[" + std::to_string(this->objectCount()) + "]" + " =====", false);
	int i = 0;
	for (auto x : objectMap)
	{
		i++;
		Logger::log(std::to_string(i) + ": " + x.first, false);
	}
	Logger::log("======================", false);
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