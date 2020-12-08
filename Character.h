#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character
{
	public:
		Character();
		virtual ~Character();

		virtual void Accelerate();
		void Break();

		virtual std::string WhatAmI() const = 0;
		// At compile time, it now checks if there are child classes with this function defined and not virtual

		inline float speed() const
		{
			return speed_;
		};

		inline float max_speed() const
		{
			return speed_;
		};

	protected:
		float speed_;
		float max_speed_;
};

#endif /* CHARACTER_H */