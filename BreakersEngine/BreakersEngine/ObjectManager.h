#pragma once

#include "Object.h"
#include <string>
#include <map>

namespace BE
{

	class ObjectManager
	{
		std::map<std::string, Object*> objectMap{};

	public:
		//Delete copy constructor and assign operator
		ObjectManager() {}
		ObjectManager(ObjectManager const&) = delete;
		void operator=(ObjectManager const&) = delete;

		static ObjectManager& get()
		{
			static ObjectManager instance;
			return instance;
		}

		Object * getObjectByTag(std::string tag) { return objectMap.at(tag); }
		std::map<std::string, Object*>::iterator it_begin() { return objectMap.begin(); }
		std::map<std::string, Object*>::iterator it_end() { return objectMap.end(); }
		void addObject(Object obj);
		void destroyObjectByTag(std::string tag) { objectMap.at(tag) = nullptr; objectMap.erase(tag); }
		void destroyAllObjects();
		bool tagTaken(std::string tag_);
		unsigned int objectCount() { return objectMap.size(); }

	};

} //End namespace BE