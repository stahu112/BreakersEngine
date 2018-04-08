#pragma once

#include <iostream>
#include <stack>
#include "Settings.h"
#include "Window.h"

namespace BE
{
	namespace System
	{
		class Application
		{
			std::unique_ptr<Window> window;
			Settings settings{};

		public:
			
			void run();

			Settings getSettings() const { return settings; }

			Application();
			~Application();
		
		};
	
	} //End namespace System
} //End namespace BE