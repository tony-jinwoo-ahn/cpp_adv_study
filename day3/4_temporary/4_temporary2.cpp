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
//	Point* p2 = &Point(0,0);// error. rvalue �� �ּҸ� ���Ҽ�����.

	Point& r1 = pt;//ok
//	Point& r2 = Point(0, 0); // error.

	// const lvalue reference �� lvalue �� rvalue�� ��� ����Ų��.
	const Point& r3 = Point(0, 0);// ������� �߰��Ǿ���. ����Լ��� �θ����ְ�, ������� ���� �Ұ�.
	//r3.x = 10; //error

	Point&& r4 = Point(0, 0);
	r4.x = 10; // ok
	
}
