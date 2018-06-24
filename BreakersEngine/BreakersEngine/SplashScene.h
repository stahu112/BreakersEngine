#pragma once
#include "Scene.h"

#include <memory>
#include <queue>

namespace BE {

	class SplashSceneState : public SceneState
	{
		float timer{ 0.0 };

	public:
		struct Splash
		{
			float length{ 0.0 };

			sf::Sprite background;

			void setBackground(sf::Texture tex)
			{
				background.setTexture(tex);
			}

			Splash(sf::Texture backgroundTex, float length_) : length(length_) {
				background.setTexture(backgroundTex);
			}
		};

		void addSplash(std::unique_ptr<Splash> splash);
		std::queue<std::unique_ptr<Splash>> splashes;

		virtual void onEnter() override final;
		virtual void update() override final;
		virtual void onExit() override final;

		SplashSceneState();

	};

	class SplashScene : public Scene
	{
	public:

		void initScene() override;
		void onChangeScene() override;

		SplashScene() : Scene("Splash") {};
	};

} //End namespace