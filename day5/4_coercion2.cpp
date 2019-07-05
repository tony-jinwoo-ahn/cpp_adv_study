#include <iostream>
#include <memory>

template<typename T = int, int N = 0> class {};
template<typename T = int, enable_if<Á¶°Ç, int>::type = 0> class {};

class Animal {};
class Dog : public Animal {};

int main()
{
	std::shared_ptr<Dog> pDog = std::make_shared<Dog>();
	std::shared_ptr<Animal> pAnimal = pDog; // ???

	std::default_delete<Dog> df;
	std::default_delete<Animal> da = df;
}