#pragma once
#include "Animation.h"

namespace BE {

	class SpriteSheetAnimation : public AnimationInterface
	{
		std::vector<SpriteSheetAnimationFrame> frameVector;

		unsigned length{ 0 };

	public:

		unsigned getLength() { return 0; }

		void updateAnimation() override;

		void play() override;
		void stop() override;
		void pause() override;

		void addFrame(sf::IntRect intRect, unsigned time);
		void addFrame(SpriteSheetAnimationFrame &frame);

		SpriteSheetAnimation();
		SpriteSheetAnimation(std::string name);

		~SpriteSheetAnimation();
	};

} //End namespace