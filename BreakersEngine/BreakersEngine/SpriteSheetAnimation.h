#pragma once
#include "Animation.h"

namespace BE {

	class SpriteSheetAnimation : public AnimationInterface
	{
		std::vector<SpriteSheetAnimationFrame> frameVector;

		SpriteSheetAnimationFrame* currentFrame;

	public:

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