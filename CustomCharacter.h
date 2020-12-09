#include <string>
#include <iostream>
#include "Character.h"

class CustomCharacter: public Character
{
	public:
		// Constructor
		CustomCharacter(std::string name);
		CustomCharacter(std::string name, int max_speed, int acceleration, int break_value);
		
		// Destructor
		~CustomCharacter();
		
		// Methods
		inline std::string name() const
		{
			return name_;
		};

		void Accelerate() override;
		void Break() override;

		void set_name(std::string name);
		void set_max_speed(int max_speed);
		void set_acceleration(int acceleration);
		void set_break_value(int break_value);

		std::string WhatAmI() const override;

	protected:
		// Attributes
		std::string name_;
		int acceleration_;
		int break_value_;
};