#pragma once

#include "Object.h"
#include <string>
#include <map>
#include "Logger.h"
#include "Exceptions.h"

namespace BE
{
	/*!
	 *@brief Container class for all the objects in scene
	 *
	 * Provides acces to every object in the scene
	 *
	 * @snippet
	 *
	 * ObjectManager om{};
	 *
	 * om.addObject(new Object{"New"});
	 *
	 * om.getObjectByTag("New")->someObjectFunction();
	 *
	 * om.destroyObjectByTag("New");
	 *
	 */

	class ObjectManager
	{
		std::map<std::string, Object*> objectMap{};
		std::string tag{ "" };

	public:
		/*!
		 * @brief Constructs ObjectManager with given name
		 * @param tag_ - name of the ObjectManager
		 */
		ObjectManager(std::string tag_) : tag(tag_) {}
		/*!
		 * @brief Destructor calls destroyAllObjects()
		 *
		 */
		~ObjectManager() {
			this->destroyAllObjects();
		}
		/*!
		 * @brief Use to wipe all the objects from the manager
		 * @note It cause onDestroy() calls from the objects stored
		 * @warning USE WITH CARE
		 */
		void destroyAllObjects();
		/*!
		 * @brief Check if the given tag is already taken by object stored
		 * @param tag_ - tag to check
		 * @return false - if tag is free, true if taken
		 */
		bool tagTaken(std::string tag_);
		/*!
		 * @Brief Return iterator of the object map
		 * @return begin() iterator of the object map
		 */
		std::map<std::string, Object*>::iterator it_begin() { return objectMap.begin(); }
		/*!
		* @Brief Return iterator of the object map
		* @return end() iterator of the object map
		*/
		std::map<std::string, Object*>::iterator it_end() { return objectMap.end(); }

		/*!
		 * @brief Add object to the container
		 *
		 * Adds given object to the container, if the tag is already taken it appends a number to it eg. NewObject1, NewObject2
		 *
		 * @param obj - Object to add
		 */
		void addObject(Object* obj);
		/*!
		 * @brief Call update method from all the stored objects
		 *
		 */
		void callUpdate();
		/*!
		* @brief Call lateUpdate method from all the stored objects
		*
		*/
		void callLateUpdate();
		/*!
		 * @brief Get pointer to the stored object with given tag
		 *
		 * @param tag_ - tag of the object to get
		 * @return Object pointer
		 */
		Object * getObjectByTag(std::string tag_);
		/*!
		 * @brief Destroy the stored object by given tag
		 * @param tag_ - tag of the object to destroy
		 */
		void destroyObjectByTag(std::string tag_);
		/*!
		 * @brief Get the object count
		 * @return Count of the stored objects
		 */
		unsigned int objectCount() const;
	};

} //End namespace BE