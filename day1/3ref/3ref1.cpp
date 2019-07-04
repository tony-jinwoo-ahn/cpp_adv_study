#include <iostream>
#include <vector>

class Car
{
public:
	~Car() { std::cout << "~Car" << std::endl; }
};
std::vector<Car*> v;

void foo()
{
	Car* p = new Car;
	v.push_back(p);

	// del p ok???
	std::cout << v[0] << std::endl;
	delete p;
	std::cout << v[0] << std::endl;
}
int main()
{
	foo();
	std::cout << v[0] << std::endl;
}
