#pragma once

#include <iostream>
#include <pugixml.hpp>
#include "Exceptions.h"

namespace BE
{
	namespace Assets {


		class AssetParser
		{
		public:
			void parse(std::string path)
			{
				pugi::xml_document doc;

				if (!doc.load_file(path.data())) throw BE::Exceptions::EXNoConfigFile{};

				pugi::xml_node grps = doc.child("ResourceList");

				std::cout << grps.name() << ":" << std::endl;

				for (pugi::xml_node grp = grps.first_child(); grp; grp = grp.next_sibling())
				{
					std::cout << " " << grp.name() << ":" << std::endl;
					for (pugi::xml_node child = grp.first_child(); child; child = child.next_sibling())
					{
						std::cout << "  " << child.name() << std::endl;

						for (pugi::xml_attribute attr = child.first_attribute(); attr; attr = attr.next_attribute())
						{
							std::cout << "   " << attr.name() << " = " << attr.value() << std::endl;
						}
					}
				}
				std::cout << std::endl;
			}

			AssetParser();
			~AssetParser();
		};
	} //End namespace BE
} //End namespace Assets