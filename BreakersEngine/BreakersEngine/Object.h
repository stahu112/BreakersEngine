#pragma once
#include <iostream>
#include <string>

namespace BE
{
	class Object
	{

		std::string tag{ "" };

	public:

		Object(std::string tag_ = "NewObject") : tag(tag_) {}
		~Object()
		{
			onDestroy();
		}

		std::string getTag() const { return tag; }
		void setTag(std::string str) { tag = str; }

		virtual void onInit() {}
		virtual void update() {}
		virtual void fixedUpdate() {}
		virtual void lateUpdate() {}
		virtual void onDestroy() {}
	};
}
