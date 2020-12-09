#include <string>
#include <iostream>
#include "Character.h"

class Yoshi: public Character
{
	public:
		// Contructor
		Yoshi(int crests);

		// Destructor
		~Yoshi();

		// Methods
		void Accelerate() override;
		
		inline int crests() const
		{
			return crests_;
		};

		std::string WhatAmI() const override;

	protected:
		// Attribute
		int crests_;
};