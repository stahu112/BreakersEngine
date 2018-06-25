#include "SplashScene.h"
#include "System\Application.h"

namespace BE
{
	void SplashSceneState::addSplash(sf::Texture splashTex, float splashLength, float fadeTime = 0)
	{
		splashes.emplace(splashTex, splashLength, fadeTime);
		this->length += splashLength;
	}

	void SplashScene::initScene()
	{
		Logger::log("Splash init", false);
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

		if (!splashes.empty()) {
			if (timer < splashes.front().length)
			{
				DRAW(splashes.front().background);
				timer += TIME.dt;
			}
			else
			{
				timer = 0;
				splashes.pop();
			}
		}
		else
			SCENE_MANAGER.changeScene("PlaceHolderScene");
	}

	void SplashSceneState::onExit()
	{
	}

	SplashSceneState::SplashSceneState()
	{
		addSplash(ASSET_MANAGER.getTexture("Splash1"), 4);
		addSplash(ASSET_MANAGER.getTexture("Aoyama"), 4);
	}

	void SplashSceneState::Splash::fadeIn(float timer)
	{
		auto color = fader.getFillColor();

		color.a -= TIME.dt;

	}

	void SplashSceneState::Splash::fadeOut(float timer)
	{
		auto a = background.getFillColor().a;
	}

	SplashSceneState::Splash::Splash(sf::Texture backgroundTex, float length_, float fadeTime)
		: tex(backgroundTex), length(length_) {
		background.setTexture(&tex);
		fader.setSize({ (float)WINDOW_SETTINGS.width, (float)WINDOW_SETTINGS.height });
		fader.setFillColor(sf::Color::Black);
		background.setSize({ (float)WINDOW_SETTINGS.width, (float)WINDOW_SETTINGS.height });
		if (fadeTime == 0)
			fadeTime = length / 3;
	}

} //End namespace