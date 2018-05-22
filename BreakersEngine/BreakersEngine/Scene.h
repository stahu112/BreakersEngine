#pragma once
#include "ObjectManager.h"
#include <memory>
#include "SceneState.h"

namespace BE
{
	/*!
	 * @brief Scene class for your scenes to inherit from
	 *
	 * Much like in unity engine scene in the Breakers Engine is a unique canvas to fill,
	 * every scene has its own ObjectManager, tag and SceneStateMachine
	 *
	 */
	class Scene
	{
		std::string tag{};

	public:
		/*!
		 * @brief StateMachine
		 */
		std::unique_ptr<SceneStateMachine> stateMachine;
		/*!
		 * @brief Must be called to initiate stateMachine
		 *
		 */
		void initSM(std::shared_ptr<SceneState> initState = std::make_shared<SceneState>())
		{
			if (!stateMachine)
				stateMachine = std::make_unique<SceneStateMachine>(std::unique_ptr<Scene>(this), initState);
			else
			{
				stateMachine.release();
				stateMachine = std::make_unique<SceneStateMachine>(std::unique_ptr<Scene>(this), initState);
			}
		}
		/*!
		 * @brief Get the scene name
		 *
		 * @return Scene name
		 */
		std::string getTag() { return tag; }
		/*!
		 * @brief ObjectManager of the scene
		 */
		ObjectManager objectManager{ tag + " ObjectManager" };

		/*!
		 * @brief Initiate the scene
		 *
		 */
		virtual void initScene() {}
		/*!
		 * @brief Called when the scene is about to change
		 *
		 */
		virtual void onChangeScene() {}
		/*!
		 * @brief Construct the scene with given tag
		 * @param tag_ - name of a scene
		 */
		Scene(std::string tag_ = "New Scene") : tag(tag_) { initSM(); }
		~Scene() {}


	};

} //End namespace BE