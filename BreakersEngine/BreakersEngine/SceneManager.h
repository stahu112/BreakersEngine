#pragma once
#include <map>
#include "Exceptions.h"
#include "Scene.h"

namespace BE
{

	/*!
	 * @see ObjectManager
	 * @brief Container class storing shared_ptrs to the available scenes
	 *
	 * Provides interface to Add and Change scenes
	 * @see Application
	 * @note There should be only one instance of this class, in Application class
	 *
	 */
	class SceneManager
	{
		std::map<std::string, std::shared_ptr<Scene>> sceneMap;

		std::string strToChange{ "" };

		float fadeTime{ .5f };

		bool fadeIn{ false };
		bool fadeOut{ false };
		bool noFadeOut{ false };

		unsigned short startIn{ 255 };
		unsigned short endIn{ 0 };
		unsigned short startOut{ 0 };
		unsigned short endOut{ 255 };
		float fadeTimer{ 0 };

	public:

		sf::RectangleShape fader;

		/*!
		 * @brief Construct new SceneManager with initial scene
		 * @param scn - First scene to load
		 */

		 //TODO SPLASH SCENE
		SceneManager();
		/*!
		 * @brief Destructor clears the scene container
		 *
		 */
		~SceneManager()
		{
			currentScene.release();
			sceneMap.clear();
		}
		/*!
		 * @brief Pointer to the active scene
		 *
		 */
		std::unique_ptr<Scene> currentScene;
		/*!
		 * @brief Add scene to the pool
		 * @param scn - shared_ptr to Scene to add
		 * @param overwrite - if scene with given tag is already stored, overrides it if set to true, else returns and logs
		 */
		void addScene(std::shared_ptr<Scene> scn, bool overwrite = false);
		/*!
		 * @brief Change active scene
		 * @param str - tag of the scene you're willing to change to
		 * @warning THROWS EXSceneWithNameNotFound if there's no scene with given tag
		 */
		void changeScene(std::string str);
		void changeSceneFade(std::string str, bool noFadeOut = false);
		void updateFader(float timer, sf::Vector2f size);
		/*!
		 * @brief Get Scene count
		 *
		 * @return Count of the stored scenes
		 */
		unsigned int getSceneCount() { return sceneMap.size(); }



	};

}