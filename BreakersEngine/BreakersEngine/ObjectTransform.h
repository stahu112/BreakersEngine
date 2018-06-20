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
		long zIndex{ 0 };
		float rotation{ 0 };

		std::vector<Transform*> children;

	public:

		static const sf::Vector2f right() { sf::Vector2f vec{ 1,0 }; return vec; }
		static const sf::Vector2f left() { sf::Vector2f vec{ -1,0 }; return vec; }
		static const sf::Vector2f up() { sf::Vector2f vec{ 0,-1 }; return vec; }
		static const sf::Vector2f down() { sf::Vector2f vec{ 0,1 }; return vec; }
		static const sf::Vector2f zero() { sf::Vector2f vec{ 0,0 }; return vec; }

		void addChild(Transform& tr)
		{
			children.push_back(&tr);
		}

		unsigned int getChildrenCount() { return children.size(); }

		long getZIndex() const { return this->zIndex; }
		void setZIndex(long newz) { this->zIndex = newz; }

		sf::Vector2f getPosition() const { return position; }
		sf::Vector2f getScale() const { return scale; }
		float getRotation() const { return rotation; }

		void setPosition(sf::Vector2f vec)
		{
			for (auto x : children)
			{
				auto delta = x->position - this->position;
				x->position = vec + delta;
			}
			this->position = vec;

		}
		void setRotation(float angle)
		{
			for (auto x : children)
			{
				auto delta = x->rotation - this->rotation;
				x->rotation = angle + delta;
			}
			this->rotation = angle;
		}
		void rotate(float angle)
		{
			for (auto x : children)
			{
				x->rotation += angle;
			}
			this->rotation += angle;
		}

		void setScale(sf::Vector2f vec)
		{
			for (auto x : children)
			{
				auto delta = x->scale - this->scale;
				x->scale = vec + delta;
			}
			this->scale = vec;
		}

		void translate(sf::Vector2f moveVec) {
			for (auto x : children)
			{
				x->position += moveVec;
			}
			this->position += moveVec;
		}

		Transform() {}
		~Transform() {
			for (auto x : children)
			{
				x = nullptr;
			}
			children.clear();
		}

	};

}