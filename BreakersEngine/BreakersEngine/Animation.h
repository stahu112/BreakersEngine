#pragma once
#include <SFML\Graphics.hpp>

namespace BE
{

	struct SpriteSheetAnimationFrame
	{
		sf::IntRect rect{ 0,0,0,0 };

		//Time of frame in frames
		float frameTime{ 0 };

		//First two arguments are the position of top left corner of the frame from spritesheet
		//Two next are width and height of the frame
		//time is the time that the frame will last 
		SpriteSheetAnimationFrame(sf::IntRect intRect, float time) : rect(intRect), frameTime(time) {}
	};

	enum AnimationStatus
	{
		PLAYING,
		STOPPED,
		PAUSED,
		FINISHED,
		IDLE
	};

	class AnimationInterface
	{
	protected:
		AnimationStatus status = IDLE;
		bool loop{ false };

		std::string name_{ "" };
		float length{ 0 };

		float counter{ 0 };
		unsigned frameCounter{ 0 };

	public:

		//Virtuals
		virtual void updateAnimation(float dt) = 0;

		virtual void play() = 0;
		virtual void stop() = 0;
		virtual void pause() = 0;

		void setLooped(bool bl) { loop = bl; }
		bool isLooped() { return loop; }
		float getLength() { return length; }

		AnimationStatus getStatus() { return status; }
		AnimationInterface(std::string name) : name_(name) {}
	};



}