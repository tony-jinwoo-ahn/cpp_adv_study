#include <iostream>
#include <memory>


int main()
{
	Freer f;
	unique_ptr<int, Freer> p1(new int, std::move(f));
	
}
