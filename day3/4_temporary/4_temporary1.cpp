#include <iostream>

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};
int main()
{
	//Point p1(1, 2);// 이름있는 객체.  named object
	//Point(1, 2); // 임시객체. unnamed object
	//Point(1, 2), std::cout << "X" << std::endl, Point(11, 22); // 수명체크

	//Point&& r = Point(1, 2);
	const Point& r = Point(1, 2);

	std::cout << "-------" << std::endl;
}
