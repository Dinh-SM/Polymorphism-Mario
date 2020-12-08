#include <string>

class Character
{
	public:
		Character();
		~Character();

		void Accelerate();
		void Break();

		

		inline float speed() const
		{
			return speed_;
		};

	protected:
		float speed_;
		float max_speed_;
};