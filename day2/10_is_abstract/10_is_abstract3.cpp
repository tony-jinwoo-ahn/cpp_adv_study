// 143 page 멤버 디텍터

#include <iostream>
#include <type_traits>

class Shape
{
public:
	//	virtual void Draw() = 0;
};


template<typename T> short Test(T(*arr)[1]); 
template<typename T> char Test(...); 

template<typename T> struct is_abstract
{
	static constexpr bool value = (sizeof(Test<T>(0)) == 1);
};
int main()
{
	bool b = is_abstract<Shape>::value;
	int n = sizeof(Test<Shape>(0));

	std::cout << n << std::endl;
}
