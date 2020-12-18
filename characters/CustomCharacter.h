#include <string>
#include <iostream>
#include "Character.h"

class CustomCharacter: public Character
{
	public:
		// Constructor
		CustomCharacter(std::string name);
		CustomCharacter(std::string name, float max_speed, float acceleration, float break_value);
		
		// Destructor
		~CustomCharacter();
		 
		// Methods
		inline std::string name() const
		{
			return name_;
		};

		inline float acceleration() const
		{
			return acceleration_;
		};

		inline float break_value() const
		{
			return break_value_;
		};

		void Accelerate() override;
		void Break() override;

		void set_name(std::string name);
		void set_max_speed(float max_speed);
		void set_acceleration(float acceleration);
		void set_break_value(float break_value);

		std::string WhatAmI() const override;

	protected:
		// Attributes
		std::string name_;
		float acceleration_;
		float break_value_;
};