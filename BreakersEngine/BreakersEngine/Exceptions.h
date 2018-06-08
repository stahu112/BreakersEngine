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
		struct EXBindingAlreadyExists : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Binding already exists!";
			}
		};
		struct EXBindingDoesntExists : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Such binding doesnt exists!";
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
		struct EXAssetNotValid : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Given asset is not valid for the Breakers Engine! Check XML asset loading file!";
			}
		};
		struct EXAssetAlreadyExists : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Asset with that name actually exists!";
			}
		};
	}
}