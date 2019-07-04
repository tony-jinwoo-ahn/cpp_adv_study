#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};

void foo(const Point& p) {} // 이거쓰면 lvalue, rvalue 다 받을 수 있어서 좋다.
//void foo(Point&& p) {} // 이렇게 forward 하면 임시객체만 받을 수 있는데, 가끔 진짜 객체 받고싶을 때 아쉽다.

int main()
{
	//Point pt(1, 2);
	//foo(pt);

	// 함수 인자로 임시객체를 전달하는 경우가 많다. (일회용)
	foo(Point(10,20));
	
	cout << "---------------" << endl;
}
