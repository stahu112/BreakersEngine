#pragma once
#include <SFML\Graphics.hpp>

namespace BE
{

	struct SpriteSheetAnimationFrame
	{
		sf::IntRect rect{ 0,0,0,0 };

		//Time of frame in frames
		unsigned frameTime{ 0 };

		//First two arguments are the position of top left corner of the frame from spritesheet
		//Two next are width and height of the frame
		//time is the time that the frame will last 
		SpriteSheetAnimationFrame(sf::IntRect intRect, unsigned time) : rect(intRect), frameTime(time) {}
	};

	enum AnimationStatus
	{
		PLAYING,
		STOPPED,
		PAUSED,
		IDLE
	};

	class AnimationInterface
	{
		AnimationStatus status = IDLE;
		bool loop{ false };

		std::string name{ "" };

	public:

		virtual void updateAnimation() = 0;

		virtual void play() = 0;
		virtual void stop() = 0;
		virtual void pause() = 0;

		void setLooped(bool bl) { loop = bl; }
		bool isLooped() { return loop; }

		AnimationStatus getStatus() { return status; }
	};



}