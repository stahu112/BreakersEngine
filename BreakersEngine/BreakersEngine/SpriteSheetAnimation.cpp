#include "SpriteSheetAnimation.h"
#include <iostream>
namespace BE {

	void SpriteSheetAnimation::updateAnimation(float dt)
	{
		if (status == PLAYING) {

			currentFrame = &frameVector[frameCounter];
			if (counter < currentFrame->frameTime)
			{
				counter += dt;
			}
			else
			{
				counter = 0;
				frameCounter++;
				if (frameCounter > frameVector.size() && loop)
				{
					frameCounter = 0;
				}
				else if (!loop)
				{
					status = FINISHED;
					frameCounter = 0;
					return;
				}
			}
		}
	}

	void SpriteSheetAnimation::play()
	{
		status = PLAYING;
	}
	void SpriteSheetAnimation::stop()
	{
		status = STOPPED;
		frameCounter = 0;
		counter = 0;
	}
	void SpriteSheetAnimation::pause()
	{
		status = PAUSED;
	}
	void SpriteSheetAnimation::addFrame(sf::IntRect intRect, float time)
	{
		frameVector.emplace_back(intRect, time);
		length += time;
	}
	void SpriteSheetAnimation::addFrame(SpriteSheetAnimationFrame & frame)
	{
		length += frame.frameTime;
		frameVector.push_back(frame);
	}

}