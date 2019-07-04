#include <iostream>
struct Point
{
	int x, y;
};

int main()
{
	int n = 0;
	int* p1 = &n;
	int Point::*px = &Point::x; // ����ü �ȿ��� x�� ��ġ (offset)
	int Point::*p2 = &Point::y; // ����ü �ȿ��� y�� ��ġ (offset)
	
	Point pt;
	pt.*p2 = 10; // *(((char*)&pt) + p2) = 10

	printf("%d \n", px);
	printf("%d \n", p2);

	printf("%d \n", pt.y);
	
	// p2 = p2 + 1; // error. ���� �ȵ�. ���� ����������� Ÿ���� �ٸ��� �����Ƿ�.
}