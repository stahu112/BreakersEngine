#pragma once

#include "Object.h"
#include <string>
#include <map>
#include "Logger.h"

namespace BE
{

	class ObjectManager
	{
		std::map<std::string, Object*> objectMap{};
		std::string tag{ "" };

	public:
		ObjectManager(std::string tag_) : tag(tag_) {}
		~ObjectManager() {
			this->destroyAllObjects();
		}

		void destroyAllObjects();
		bool tagTaken(std::string tag_);
		std::map<std::string, Object*>::iterator it_begin() { return objectMap.begin(); }
		std::map<std::string, Object*>::iterator it_end() { return objectMap.end(); }
		void addObject(Object* obj);

		void callUpdate();
		void callLateUpdate();

		Object * getObjectByTag(std::string tag_)
		{
			Logger::log("From: " + this->tag + ": Get by tag: " + tag_);
			return objectMap.at(tag_);
		}

		void destroyObjectByTag(std::string tag_) {
			delete objectMap.at(tag_);
			objectMap.erase(tag_);
		}
		unsigned int objectCount() {
			Logger::log("Object count of: " + this->tag + " = " + std::to_string(objectMap.size()));
			return objectMap.size();
		}
	};

} //End namespace BE