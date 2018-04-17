#pragma once
#include <iostream>
#include <string>

namespace BE
{
	class Object
	{
		static unsigned int globalCount;

		std::string tag{ "" };

	public:

		Object()
		{
			globalCount++;
		}
		~Object()
		{
			onDestroy();
			globalCount--;
		}

		std::string getTag() const { return tag; }
		void setTag(std::string str) { tag = str; }

		void destroy() { delete this; }

		virtual void onInit() {}
		virtual void update() {}
		virtual void fixedUpdate() {}
		virtual void lateUpdate() {}
		virtual void onDestroy() {}
	};
}
