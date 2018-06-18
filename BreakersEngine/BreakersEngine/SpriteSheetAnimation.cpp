#include "SpriteSheetAnimation.h"
#include <iostream>
namespace BE {

	void SpriteSheetAnimation::updateAnimation(float dt)
	{
		if (status == PLAYING) {

			if (counter < currentFrame->frameTime)
			{
				counter += dt;
			}
			else
			{
				counter = 0;
				frameCounter++;
				if (frameCounter >= frameVector.size() && !loop)
				{
					status = FINISHED;
					frameCounter = 0;
					return;
				}
				else if(frameCounter >= frameVector.size())
				{
					frameCounter = 0;
				}
			}
			
			currentFrame = &frameVector[frameCounter];
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
		currentFrame = &frameVector[0];

	}
	void SpriteSheetAnimation::addFrame(SpriteSheetAnimationFrame & frame)
	{
		length += frame.frameTime;
		frameVector.push_back(frame);
		currentFrame = &frameVector[0];
	}

}