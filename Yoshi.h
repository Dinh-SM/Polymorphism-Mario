#include <string>
#include <iostream>
#include "Character.h"

class Yoshi: public Character
{
	public:
		Yoshi(int crests);
		~Yoshi();

		void Accelerate() override;
		
		inline int crests() const
		{
			return crests_;
		};

		std::string WhatAmI() const override;

	protected:
		int crests_;
};