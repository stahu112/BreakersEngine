#include "SceneState.h"
#include "Scene.h"

BE::SceneStateMachine::SceneStateMachine(std::unique_ptr<Scene> parent, std::unique_ptr<SceneState> initialState)
{
	parentScene = std::move(parent);
	currentState = std::move(initialState);
}

bool BE::SceneStateMachine::changeState(std::unique_ptr<SceneState> newState)
{
	if (stateStack.size() == 1)
	{ //Must have at least 1 element
		Logger::log("From: " + parentScene->getTag() + " basic state cannot be removed! Use 'pushState' instead!");
		return false;
	}
	else
	{
		stateStack.pop();
		stateStack.push(std::move(newState));
		return true;
	}
}

void BE::SceneStateMachine::pushState(std::unique_ptr<SceneState> newState)
{
	stateStack.push(std::move(newState));
}

bool BE::SceneStateMachine::popState()
{
	if (stateStack.size() == 1)
	{
		Logger::log("From: " + parentScene->getTag() + " basic state cannot be removed!");
		return false;
	}
	else
	{
		stateStack.pop();
	}
}
