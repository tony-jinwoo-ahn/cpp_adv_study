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
	Point pt;
	Point* p1 = &pt;// ok
//	Point* p2 = &Point(0,0);// error. rvalue 는 주소를 구할수없다.

	Point& r1 = pt;//ok
//	Point& r2 = Point(0, 0); // error.

	// const lvalue reference 는 lvalue 와 rvalue를 모두 가리킨다.
	const Point& r3 = Point(0, 0);// 상수성이 추가되었다. 상수함수만 부를수있고, 멤버변수 수정 불가.
	//r3.x = 10; //error

	Point&& r4 = Point(0, 0);
	r4.x = 10; // ok
	
}
