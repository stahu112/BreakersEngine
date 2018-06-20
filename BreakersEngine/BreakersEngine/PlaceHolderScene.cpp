#include "PlaceHolderScene.h"
#include "System\Application.h"

void Aoyama::update()
{
	anim.updateAnimation(TIME.dt);

	if (INPUT_MANAGER.keyHeld("test")) {
		transform.translate({ 1000 * TIME.dt, 0 });
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

void Aoyama::fixedUpdate()
{
	transform.setPosition({ 300,300 });
}

void Aoyama::draw()
{
	sp.setTextureRect(anim.getFrame()->rect);
	DRAW(sp);
}

void Aoyama::onInit()
{
	sp.setTexture(ASSET_MANAGER.getTexture("Anim"));

	transform.setPosition({ 100, 100 });
	
	anim.addFrame({ 0,0,512,256 }, .05f);
	anim.addFrame({ 512,0,512,256 }, .05f);
	anim.addFrame({ 0,256,512,256 }, .05f);
	anim.addFrame({ 512,256,512,256 }, .1f);
	anim.addFrame({ 0,512,512,256 }, .1f);
	anim.addFrame({ 512,512,512,256 }, .1f);
	anim.addFrame({ 0,768,512,256 }, .05f);
	anim.addFrame({ 512,768,512,256 }, .05f);

	snd.setBuffer(ASSET_MANAGER.getSound("Sound"));

	anim.setLooped(true);
	anim.play();

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
	TIME.fixedDt = 1000;
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
			TIME.timeScale += 1;
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
