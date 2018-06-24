#include "SplashScene.h"
#include "System\Application.h"

namespace BE
{
	void SplashSceneState::addSplash(std::unique_ptr<Splash> splash)
	{
		splashes.push(std::move(splash));
	}

	void SplashScene::initScene()
	{
		this->initSM(std::make_shared<SplashSceneState>());
	}

	void SplashScene::onChangeScene()
	{
		Logger::log("Splashes ended", false);
	}

	void SplashSceneState::onEnter()
	{

	}

	void SplashSceneState::update()
	{
		while (!splashes.empty())
		{
			if (timer < splashes.front()->length)
				DRAW(splashes.front()->background);
			else
			{
				splashes.pop();
				timer = 0;
			}
		}
		SCENE_MANAGER.changeScene("PlaceholderScene");
	}

	void SplashSceneState::onExit()
	{
	}

	SplashSceneState::SplashSceneState()
	{

	}

} //End namespace