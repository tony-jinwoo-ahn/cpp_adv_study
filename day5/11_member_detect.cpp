#include <iostream>
#include <type_traits>

struct Point
{
	int x; //이거 주석 풀면 1 된다. x 가 있는지 없는지 체크.
	int y;
};

// 타입 받고, 그 타입의 값 받겠다는 의미
template<typename T, T> struct check;
// check<int, 0>
// check<int Point::*, &Point::x> 포인트클래스의 멤버 x가 있으면 괜찮은데, 없으면 문제다
// check<int*, 0>

template<typename T> struct has_member_x
{
	typedef char YES[1];
	typedef char NO[2];

	template<typename U>
	static YES& Test(check< int U::*, &U::x > * p); // 전체 결과는 check 타입의 포인터(*) 이다.

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
