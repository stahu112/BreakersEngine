#pragma once

#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>
#include "Logger.h"

namespace BE
{
	class Transform
	{

		sf::Vector2f position{ 0,0 };
		sf::Vector2f scale{ 1,1 };
		float rotation{ 0 };

	public:

		static const sf::Vector2f& right() { sf::Vector2f vec{ 1,0 }; return vec; }
		static const sf::Vector2f& left() { sf::Vector2f vec{ -1,0 }; return vec; }
		static const sf::Vector2f& up() { sf::Vector2f vec{ 0,-1 }; return vec; }
		static const sf::Vector2f& down() { sf::Vector2f vec{ 0,1 }; return vec; }
		static const sf::Vector2f& zero() { sf::Vector2f vec{ 0,0 }; return vec; }

		sf::Vector2f getPosition() const { return position; }
		sf::Vector2f getScale() const { return scale; }
		float getRotation() const { return rotation; }

		void setPosition(sf::Vector2f vec)
		{
			this->position = vec;
		}
		void setRotation(float angle)
		{
			this->rotation = angle;
		}
		void rotate(float angle)
		{
			this->rotation += angle;
		}

		void setScale(sf::Vector2f vec)
		{
			this->scale = vec;
		}

		void translate(sf::Vector2f moveVec) {
			this->position += moveVec;
		}

		Transform() {}
		~Transform() {}

	};

}