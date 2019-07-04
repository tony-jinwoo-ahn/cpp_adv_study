#include <iostream>

struct Point
{
	int x;
	int y;
};
int main()
{
	int n = 0;
	int* p1 = &n;
//	int* p2 = &Point::y; // error

	//int Point::*  �ǹ�: Point Ŭ���� �ȿ��ִ� int�� �ּ�
	int Point::*p2 = &Point::y; // ok. ����� �ּ�.
								// pointer to member ���.

	// �� �ڵ� ��𿡼��� Point ��ü�� �޸𸮿� �������� ����.
	std::cout << p2 << std::endl; // offset_of ���. 4�� ���;� �ϴµ� cout �Ѱ�� 1�� ����.
	printf("%d\n", p2); // ��Ȯ�� ������ ����.

	Point pt;
	pt.*p2 = 10; // �ᱹ p2.y = 10 �� ���� �ǹ�.
				// .* : pointer to member operator
	printf("%d\n", p2); // ��Ȯ�� ������ ����.

	p2 = &Point::x;
	printf("%d\n", p2); // ��Ȯ�� ������ ����.

	

}
