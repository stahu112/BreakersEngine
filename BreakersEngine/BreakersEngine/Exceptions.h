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
		struct EXTryingToPopInitialState : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "You can't pop the initial state!";
			}
		};
		struct EXNoAsset : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "There's no such asset!;";
			}
		};
		struct EXWrongPath : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "NOT FOUND! Invalid path!";
			}
		};
		struct EXNoConfigFile : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "XML Configuration file not found!";
			}
		};
	}
}