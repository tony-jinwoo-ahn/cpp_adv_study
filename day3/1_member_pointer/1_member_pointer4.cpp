#include <iostream>
struct Point
{
	int x, y;
};

int main()
{
	int n = 0;
	int* p1 = &n;
	int Point::*px = &Point::x; // 구조체 안에서 x의 위치 (offset)
	int Point::*p2 = &Point::y; // 구조체 안에서 y의 위치 (offset)
	
	Point pt;
	pt.*p2 = 10; // *(((char*)&pt) + p2) = 10

	printf("%d \n", px);
	printf("%d \n", p2);

	printf("%d \n", pt.y);
	
	// p2 = p2 + 1; // error. 덧셈 안됨. 다음 멤버데이터의 타입이 다를수 있으므로.
}