#pragma once
#include "Scene.h"
#include <map>
#include "Exceptions.h"

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


	public:
		/*!
		 * @brief Construct new SceneManager with initial scene
		 * @param scn - First scene to load
		 */

		SceneManager(std::shared_ptr<Scene> scn = std::make_shared<Scene>("PlaceHolderScene")) {

			addScene(scn);
			currentScene.reset(scn.get());
			currentScene->initScene();
		}
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

		/*!
		 * @brief Get Scene count
		 *
		 * @return Count of the stored scenes
		 */
		unsigned int getSceneCount() { return sceneMap.size(); }



	};

}