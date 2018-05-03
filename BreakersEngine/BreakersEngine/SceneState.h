#pragma once

#include <stack>
#include <memory>

namespace BE
{
	class Scene;

	class SceneState
	{

	public:
		virtual void onEnter() {}
		virtual void update() {}
		virtual void onExit() {}

	protected:



	};

	class SceneStateMachine
	{
		std::unique_ptr<Scene> parentScene;
		std::unique_ptr<SceneState> currentState;

		std::stack<std::unique_ptr<SceneState>> stateStack;

	public:
		//TODO Make some default state
		SceneStateMachine(std::unique_ptr<Scene> parent, std::unique_ptr<SceneState> initialState);
		~SceneStateMachine() {
			parentScene.release();
			currentState.release();
		}

		//State Functions
		bool changeState(std::unique_ptr<SceneState> newState);
		void pushState(std::unique_ptr<SceneState> newState);
		bool popState();
	};

} //End namespace BE