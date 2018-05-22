#pragma once
#include <iostream>
#include <stack>
#include <memory>
#include"Logger.h"

namespace BE
{
	class Scene;
	/*!
	 * @brief parent class for scene states
	 *
	 */
	class SceneState
	{

		friend class SceneStateMachine;
		std::string getName() { return typeid(*this).name(); }
		int i = 0;
	public:
		SceneState();
		virtual void onEnter() { Logger::log(getName() + " OnEnter"); }
		virtual void update();
		virtual void onExit() { Logger::log(getName() + " OnExit"); }

	};

	/*!
	 * @brief State machine for managing ScenStates
	 *
	 * Every Scene has its own SceneStateMachine that do stuff depending on the current SceneState
	 *
	 * It's based on stack with the inital gameplay state (Playing state),
	 * and then it can be changed to the Pause state for example,
	 * or Cutscene state all placed on top of the initial state.
	 *
	 *@warning
	 * -Stack need to have at least one element (Playing state)
	 *
	 */
	class SceneStateMachine
	{

		std::stack<std::shared_ptr<SceneState>> stateStack;

	public:
		/*!
		 * @brief Update loop
		 * Calls all the necessary stuff like update and object manager callUpdate
		 *
		 */
		void updateLoop();
		std::shared_ptr<SceneState> getActiveState() { return stateStack.top(); };
		/*!
		 * @brief Pointer to the Scene to witch the instance of SceneStateMachine belongs
		 *
		 */
		std::unique_ptr<Scene> parentScene;
		/*!
		 * @brief Construct the StateMachine with given initial state
		 * @param parent - Pointer to the parent scene
		 * @param initialState - The initial "Base" state (Should be Playing state)
		 */
		SceneStateMachine(std::unique_ptr<Scene> parent, std::shared_ptr<SceneState> initialState);
		~SceneStateMachine() {
			parentScene.release();
		}

		/*!
		 * @brief Get stack elemnts count
		 * @return Actual size of the state stack
		 */
		unsigned int getStackSize() { return stateStack.size(); }
		//State Functions
		/*!
		 * @brief Pop current state and instantly push new one to the stack
		 * @param newState - SceneState to be changed to
		 * @throw EXTryingToPopInitialState if failed
		 */
		void changeState(std::shared_ptr<SceneState> newState);
		/*!
		* @brief Push new SceneState on the top of the active state
		* @param newState - SceneState to be changed to
		*/
		void pushState(std::shared_ptr<SceneState> newState);
		/*!
		 * @brief Pop the active state from the state stack
		 * @throw EXTryingToPopInitialState if failed
		 */
		void popState();
		std::string stringifyActiveState();
	};

} //End namespace BE