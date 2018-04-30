#pragma once
#include <iostream>
#include <string>
#include "Logger.h"

namespace BE
{
	class Object
	{
		friend class ObjectManager;
		std::string tag{ "" };

	public:

		Object(std::string tag_ = "NewObject") : tag(tag_) {}
		~Object()
		{
			onDestroy();
		}

		std::string getTag() const { return tag; }
		void setTag(std::string str) { tag = str; }

	protected:
		virtual void onInit() { Logger::log(tag + " Initiated"); }
		virtual void update() {}
		virtual void fixedUpdate() {}
		virtual void lateUpdate() {}
		virtual void onDestroy() { Logger::log(tag + " Destroyed"); }
	};
}
