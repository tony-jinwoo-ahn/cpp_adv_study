// tuple Å©±â
#include <iostream>
#include <tuple>

struct Empty {};

int main()
{
	std::tuple<Empty, int> t1;
	std::cout << sizeof(t1) << std::endl;
	
}