#pragma once
#include "Object.h"
#include "Scene.h"

class Aoyama : public BE::Object
{
	sf::Sprite sp;

	void update() override final
	{
		this->transform.translate({ 1,1 });
		this->transform.rotate(3);
		sp.setPosition(this->transform.getPosition());
		sp.setRotation(this->transform.getRotation());
	}

	void draw() override final;
	void onInit() override;

public:
	void setTex(sf::Texture tex)
	{
		sp.setTexture(tex);
	}

	Aoyama();
};

class MySceneState : public BE::SceneState
{
	virtual void onEnter() override final;
	virtual void update() override final;
	virtual void onExit() override final;
public:
	MySceneState();

};

class PlaceHolderScene : public BE::Scene
{
public:
	PlaceHolderScene();
	void initScene() override final;
};

