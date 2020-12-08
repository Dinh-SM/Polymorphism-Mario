#include <string>

class Character
{
	public:
		Character();
		~Character();

		void Accelerate();
		void Break();

		virtual std::string WhatAmI() const = 0;

		inline float speed() const;

	protected:
		float speed_;
		float max_speed_;
};