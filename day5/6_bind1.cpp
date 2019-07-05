//6_bind
#include <iostream>
#include <functional>
using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d \n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4);
	// bind : N ���� �Լ� ���ڸ� �����ؼ� M(<N) ���� �Լ��� ����� ����

	std::bind(&foo, 10, _1, 30, _2)(5, 7); // 10, 5, 30, 7
	std::bind(&foo, 10, 5, 30, 7)(); // 10, 5, 30, 7
	std::bind(&foo, _3, 7, _1, _2)(5, 3, 2); // 2, 7, 5, 3
}
