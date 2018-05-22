#include "PlaceHolderScene.h"
#include "System\Application.h"

void Aoyama::draw()
{
	DRAW(sp);
}

void Aoyama::onInit()
{
	sp.setTexture(ASSET_MANAGER.getTexture("Aoyama"));
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
	BE::Logger::log("ent");
}

void MySceneState::update()
{
	BE::Logger::log("upd");
}

void MySceneState::onExit()
{
	BE::Logger::log("exi");
}
