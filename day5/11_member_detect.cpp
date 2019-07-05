#include <iostream>
#include <type_traits>

struct Point
{
	int x; //�̰� �ּ� Ǯ�� 1 �ȴ�. x �� �ִ��� ������ üũ.
	int y;
};

// Ÿ�� �ް�, �� Ÿ���� �� �ްڴٴ� �ǹ�
template<typename T, T> struct check;
// check<int, 0>
// check<int Point::*, &Point::x> ����ƮŬ������ ��� x�� ������ ��������, ������ ������
// check<int*, 0>

template<typename T> struct has_member_x
{
	typedef char YES[1];
	typedef char NO[2];

	template<typename U>
	static YES& Test(check< int U::*, &U::x > * p); // ��ü ����� check Ÿ���� ������(*) �̴�.

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
