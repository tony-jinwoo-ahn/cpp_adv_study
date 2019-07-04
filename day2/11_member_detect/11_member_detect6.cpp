#include <iostream>
#include <type_traits>

struct Point
{
	int x;
	int y;
};

template<typename T, T> struct check;
// <Point, Point::*>

template<typename T> struct has_member_x
{
	typedef char YES[1];
	typedef char NO[2];

	template<typename U> 
	static YES& Test( check<U, &U::x>* p );

	template<typename U> 
	static NO& Test(...);

	static constexpr bool value =
		(sizeof(Test<T>(0)) == sizeof(YES));
};
int main()
{
	bool b = has_member_x<Point>::value;
	std::cout << b << std::endl;
}
