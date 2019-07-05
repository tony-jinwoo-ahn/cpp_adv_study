#include <iostream>
#include <functional>

using namespace std::placeholders;

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d \n", a, b, c, d);
}

int main()
{
	void(*f1)(int); // ���ڰ� �Ѱ��� �Լ� �ּҸ� ���� �� �ִ�.

	// cpp11���� �߰��� �Լ������� ������ ���ø�
	// �ַ� bind �� ���� ����Ѵ�.
	std::function<void(int)> f;

	//f = &foo;
	f = std::bind(&foo, _1, 0, 0, 0);
	f(10); // 10, 0, 0, 0

//	f = std::bind(&goo, _1, "�׽�Ʈ��");
}

// �ݹ鿡�� �پ��� ������ ���ڸ� ���� �� �ִ� ������.
