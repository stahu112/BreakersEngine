#include "SceneManager.h"
#include "SplashScene.h"
#include "PlaceHolderScene.h"

//TODO SPLASH SCENE
BE::SceneManager::SceneManager() {
	std::shared_ptr<Scene> scn = std::make_shared<Scene>();
	addScene(scn);
	addScene(std::make_shared<SplashScene>());
	addScene(std::make_shared<PlaceHolderScene>());
	addScene(std::make_shared<PlaceHolderScene>("1"));
	addScene(std::make_shared<PlaceHolderScene>("2"));
	currentScene.reset(scn.get());

	fader.setFillColor(sf::Color::Black);
}

void BE::SceneManager::addScene(std::shared_ptr<Scene> scn, bool overwrite) {

	if (sceneMap.find(scn->getTag()) == sceneMap.end())
	{
		sceneMap.insert(std::make_pair(scn->getTag(), scn));
	}
	else
	{
		if (!overwrite)
		{
			Logger::log("There's already a scene with tag: " + scn->getTag() + " in the scene pool");
		}
		else
		{
			sceneMap.at(scn->getTag()).reset(scn.get());
			Logger::log("Overwritten " + scn->getTag() + " scene");
		}
	}
}

void BE::SceneManager::changeScene(std::string str)
{
	if (sceneMap.find(str) == sceneMap.end())
	{
		Logger::log("There's no scene with name: " + str + " in the manager");
		throw Exceptions::EXSceneWithNameNotFound{};
	}
	else
	{
		currentScene->onChangeScene();
		currentScene.release();
		currentScene.reset(sceneMap.at(str).get());
		currentScene->initScene();
	}
}

void BE::SceneManager::changeSceneFade(std::string str, bool noFade)
{
	fadeOut = true;
	fadeIn = true;
	strToChange = str;
	if (noFade)
	{
		noFadeOut = true;
		fadeOut = false;
	}
}

void BE::SceneManager::updateFader(float timer, sf::Vector2f size)
{
	auto color = fader.getFillColor();
	fader.setFillColor(color);

	if (noFadeOut)
	{
		changeScene(strToChange);
		noFadeOut = false;
	}

	if (fadeIn && !fadeOut && fadeTimer < 0.5) {


		fader.setSize(size);
		fadeTimer += timer;

		endIn = 0;
		startIn = 255;

		color.a = startIn + (endIn - startIn) * (fadeTimer / 0.5);


		fader.setFillColor(color);
		if (fadeTimer > 0.5) {
			fadeTimer = 0;
			color.a = 0;
			fader.setFillColor(color);
			fadeIn = false;
		}
	}
	fader.setFillColor(color);

	if (fadeOut && fadeTimer < 0.5) {


		fader.setSize(size);
		//auto color = fader.getFillColor();
		fadeTimer += timer;

		startOut = 0;
		endOut = 255;

		color.a = startOut + (endOut - startOut) * (fadeTimer / 0.5);

		fader.setFillColor(color);
		if (fadeTimer > 0.5) {
			fadeTimer = 0;
			fadeOut = false;
			color.a = 255;
			changeScene(strToChange);
		}
	}
	fader.setFillColor(color);
}
