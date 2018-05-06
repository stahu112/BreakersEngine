#include "SceneState.h"
#include "Scene.h"

BE::SceneStateMachine::SceneStateMachine(std::unique_ptr<Scene> parent, std::shared_ptr<SceneState> initialState)
{
	parentScene = std::move(parent);
	stateStack.push(initialState);
	stateStack.top()->onEnter();
}

void BE::SceneStateMachine::changeState(std::shared_ptr<SceneState> newState)
{
	if (stateStack.size() <= 1)
	{ //Must have at least 1 element
		Logger::log("From: " + parentScene->getTag() + " basic state cannot be removed! Use 'pushState' instead!");
		throw Exceptions::EXTryingToPopInitialState{};
	}
	else
	{
		stateStack.top()->onExit();
		stateStack.pop();
		stateStack.push(newState);
		stateStack.top()->onEnter();
	}
}

void BE::SceneStateMachine::pushState(std::shared_ptr<SceneState> newState)
{
	stateStack.top()->onExit();
	stateStack.push(newState);
	stateStack.top()->onEnter();
}

void BE::SceneStateMachine::popState()
{
	if (stateStack.size() <= 1)
	{
		Logger::log("From: " + parentScene->getTag() + " basic state cannot be removed!");
		throw Exceptions::EXTryingToPopInitialState{};
	}
	else
	{
		stateStack.top()->onExit();
		stateStack.pop();
		stateStack.top()->onEnter();
	}
}

std::string BE::SceneStateMachine::stringifyActiveState()
{
	std::string str{ stateStack.top()->getName() };
	str.erase(0, 10);
	return str;
}
