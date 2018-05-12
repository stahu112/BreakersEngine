#pragma once
#include <iostream>
#include <string>
#include "ObjectTransform.h"
#include "Logger.h"


namespace BE
{
	/*!
	 * @brief Interface from which all your game objects should inherit
	 *
	 * Object class is an interface containing methods called each frame,
	 * you make your objects do stuff by overriding those methods
	 *
	 * @note It's really important to use this interface in your objects
	 *
	 */
	class Object
	{
	protected:
		friend class ObjectManager;
		std::string tag{ "" };
		void setTag(std::string tag_) { tag = tag_; }
		bool active = true;

	public:
		/*!
		 * @brief Objects transform
		 *
		 */
		Transform transform{};
		/*!
		 *@brief Create object with given name
		 *@param tag_ - unique name of the object, if not give it's defaulted to "NewObject"
		 *
		 */
		Object(std::string tag_ = "NewObject") : tag(tag_) {}
		/*!
		 * @brief Destructor calls onDestroy()
		 *
		 */
		virtual ~Object()
		{
			onDestroy();
		}
		/*!
		 * @brief Check if Object is active
		 * @return true if active, false if not
		 */
		bool isActive() { return active; }
		/*!
		 * @brief Activate object
		 *
		 */
		void activate();
		/*!
		* @brief Dectivate object
		*
		*/
		void dectivate();
		/*!
		 * @brief returns tag of the object
		 *
		 * @return tag of the object
		 */
		std::string getTag() const { return tag; }

	protected:

		virtual void onActivation() { Logger::log(tag + " Activated"); }
		virtual void onDeactivation() { Logger::log(tag + " Deactivated"); }
		/*!
		 * @brief called on Adding object to the manager
		 *
		 */
		virtual void onInit() { Logger::log(tag + " Initiated"); }
		/*!
		 * @brief called each frame
		 *
		 */
		virtual void update() { Logger::log(tag + " Update"); }
		/*!
		 * @brief called every constant amount of time, specified in "Time" namespace
		 *
		 * @note use it for physics calculations
		 */
		virtual void fixedUpdate() { Logger::log(tag + " FixedUpdate"); }
		/*!
		 * @brief called every frame but AFTER the regular update
		 *
		 */
		virtual void lateUpdate() { Logger::log(tag + " LateUpdate"); }
		/*!
		 * @brief called when the object is being destroyed
		 *
		 */
		virtual void onDestroy() { Logger::log(tag + " Destroyed"); }
		/*!
		 * @brief called last and manages drawing stuff
		 *
		 */
		virtual void draw() { Logger::log(tag + " Draw"); }
	};
}
