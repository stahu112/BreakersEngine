#include "PlaceHolderScene.h"
#include "System\Application.h"

void Aoyama::update()
{
	if (INPUT_MANAGER.keyHeld("test")) {
		transform.translate({ 1, 0 });
		if (snd.getStatus() != sf::Sound::Status::Playing)
			snd.play();
	}
	else
	{
		snd.pause();
	}

	if (INPUT_MANAGER.mButtonHeld("M1"))
	{
		transform.rotate(5);
	}

	sp.setPosition(this->transform.getPosition());
	sp.setRotation(this->transform.getRotation());
}

void Aoyama::draw()
{
	DRAW(sp);
}

void Aoyama::onInit()
{
	transform.setPosition({ 100, 100 });
	sp.setTexture(ASSET_MANAGER.getTexture("Aoyama"));

	snd.setBuffer(ASSET_MANAGER.getSound("Sound"));
}

Aoyama::Aoyama() : Object("Aoyama")
{
}

PlaceHolderScene::PlaceHolderScene() : Scene("PlaceHolderScene")
{
	initSM(std::make_shared<MySceneState>());
}

void PlaceHolderScene::initScene()
{
	objectManager.addObject(new Aoyama);
	BE::Logger::log("init");
}

MySceneState::MySceneState()
{

}

void MySceneState::onEnter()
{

}

void MySceneState::update()
{
	try {
		if (INPUT_MANAGER.keyReleased("Active"))
		{
			if (!ACTIVE_SCENE->objectManager.getObjectByTag("Aoyama")->isActive())
				ACTIVE_SCENE->objectManager.activate("Aoyama");
			else
				ACTIVE_SCENE->objectManager.deActivate("Aoyama");
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void MySceneState::onExit()
{

}
