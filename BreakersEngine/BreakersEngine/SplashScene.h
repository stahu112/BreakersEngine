#pragma once
#include "Scene.h"

#include <memory>
#include <queue>

namespace BE {

	class SplashSceneState : public SceneState
	{
	public:

		class Splash
		{
			sf::Texture tex;
			float fadeTime{ 2 };
			bool fadedIn{ false };

			unsigned short startIn{ 255 };
			unsigned short endIn{ 0 };
			unsigned short startOut{ 0 };
			unsigned short endOut{ 255 };


		public:

			bool done{ false };
			float length{ 0.0 };
			void fadeIn(float timer);
			void fadeOut(float timer);
			sf::RectangleShape fader;
			sf::RectangleShape background;
			Splash(sf::Texture backgroundTex, float length_);
			Splash() {}
		};

		void addSplash(sf::Texture splashTex, float splashLength);
		std::queue<Splash> splashes;

		virtual void onEnter() override final;
		virtual void update() override final;
		virtual void onExit() override final;

		SplashSceneState();

	private:
		sf::Texture tex;
		float length{ 0 };
		float timer{ 0.0 };
	};

	class SplashScene : public Scene
	{
	public:

		void initScene() override;
		void onChangeScene() override;

		SplashScene() : Scene("SplashScene") {};
	};

} //End namespace