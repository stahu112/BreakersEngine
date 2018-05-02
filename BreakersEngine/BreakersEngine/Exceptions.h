#pragma once
#include <exception>

namespace BE
{
	namespace Exceptions
	{
		struct EXObjectWithTagNotFound : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "No object with this tag!";
			}
		};
		struct EXSceneWithNameNotFound : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "No scene with this name!";
			}
		};

	}
}