#include "Cat.h"
#include "Dog.h"
#include "LazyCat.h"
#include "Frog.h"
#include "Veterinary.h"

int main()
{
	Cat cat(3, "Sarah", "Siamska");
	LazyCat lzCat(1, "Lisa", "LazyCat");
	Dog dg(10, "Roky");
	Frog fr(1, "Kermit");
	Animal an(10, "BoringAnimal");

	Veterinary vet;
	vet.AddAnimal(&cat);
	vet.AddAnimal(&lzCat);
	vet.AddAnimal(&dg);
	vet.AddAnimal(&fr);
	vet.AddAnimal(&an);

	vet.MakeSymphony();

    return 0;
}

