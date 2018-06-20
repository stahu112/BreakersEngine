#pragma once
#include "Object.h"
#include <SFML\Audio.hpp>
#include "Scene.h"
#include "SpriteSheetAnimation.h"

class Aoyama : public BE::Object
{
	sf::Sprite sp;
	sf::Sound snd;

	void update() override final;
	void fixedUpdate() override final;

	void draw() override final;
	void onInit() override;

public:

	BE::SpriteSheetAnimation anim{ "testanim" };

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

