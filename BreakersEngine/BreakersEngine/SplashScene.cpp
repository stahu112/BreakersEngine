#include "SplashScene.h"
#include "System\Application.h"

namespace BE
{
	void SplashSceneState::addSplash(sf::Texture splashTex, float splashLength)
	{
		splashes.emplace(splashTex, splashLength);
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

			if (!splashes.front().done)
			{
				splashes.front().fadeOut(timer);
				splashes.front().fadeIn(timer);
				DRAW(splashes.front().background);
				DRAW(splashes.front().fader);
				timer += TIME.dt;
			}
			else
			{
				timer = 0;
				splashes.pop();
				if (!splashes.empty())
					DRAW(splashes.front().fader);
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
		addSplash(ASSET_MANAGER.getTexture("Splash1"), 5);
		addSplash(ASSET_MANAGER.getTexture("Splash2"), 5);
	}

	void SplashSceneState::Splash::fadeIn(float timer)
	{
		auto color = fader.getFillColor();
		if (!fadedIn && timer < fadeTime) {

			static float start = 255;
			static float end = 0;

			color.a = start + (end - start) * (timer / fadeTime);
		}
		else
			fadedIn = true;
		fader.setFillColor(color);

	}

	void SplashSceneState::Splash::fadeOut(float timer)
	{
		auto color = fader.getFillColor();

		if (fadedIn && timer > length - fadeTime) {

			static float start = 0;
			static float end = 255;

			color.a = start + (end - start) * (timer / fadeTime);

			fader.setFillColor(color);
			if (color.a > 244) done = true;
		}
	}

	SplashSceneState::Splash::Splash(sf::Texture backgroundTex, float length_)
		: tex(backgroundTex), length(length_) {
		background.setTexture(&tex);
		fader.setSize({ (float)WINDOW_SETTINGS.width, (float)WINDOW_SETTINGS.height });
		fader.setFillColor(sf::Color::Black);
		background.setSize({ (float)WINDOW_SETTINGS.width, (float)WINDOW_SETTINGS.height });

		fadeTime = length / 2;
	}

} //End namespace