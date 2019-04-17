#include "Cat.h"

class LazyCat : public Cat
{
public:
	LazyCat(int age = 0, const char *name = "", const char *kind = "")
		: Cat(age, name, kind)
	{}

	void MakeNoise() const
	{
		std::cout << "Meooooooooow, I am a LAZY CAT with a name: " << GetName() << std::endl;
	}
};