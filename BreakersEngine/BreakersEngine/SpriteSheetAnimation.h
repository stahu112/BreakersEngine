#pragma once
#include "Animation.h"

namespace BE {

	class SpriteSheetAnimation : public AnimationInterface
	{
		std::vector<SpriteSheetAnimationFrame> frameVector;

		float length{ 0 };
		float counter{ 0 };
		unsigned frameCounter{ 0 };

		SpriteSheetAnimationFrame* currentFrame;

	public:

		unsigned getLength() { return 0; }

		void updateAnimation(float dt) override;

		void play() override;
		void stop() override;
		void pause() override;

		void addFrame(sf::IntRect intRect, float time);
		void addFrame(SpriteSheetAnimationFrame &frame);

		SpriteSheetAnimationFrame* getFrame() { return currentFrame; }

		SpriteSheetAnimation(std::string name) : AnimationInterface(name) {}

	};

} //End namespace