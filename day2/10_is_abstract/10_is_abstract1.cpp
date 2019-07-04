// 143 page 멤버 디텍터

#include <iostream>
#include <type_traits>

class Shape
{
public:
	virtual void Draw() = 0;
};

int main()
{
	std::cout << std::is_abstract<Shape>::value << std::endl;

}
