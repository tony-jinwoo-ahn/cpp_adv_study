#include <iostream>
// __FUNCSIG__ : �Լ��̸� + signature, VC++ ����. g++ ���� �ȵ�
// __PRETTY_FUNCTION__ : g++�� �Լ��̸�+signature
//void foo2(int& a) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

void foo(int& a)		{ std::cout << __FUNCSIG__ << std::endl; }
void foo(const int& a)  { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& a)		{ std::cout << __FUNCSIG__ << std::endl; }


int main()
{
	int n = 0;
//	foo(n); // 1�� ȣ��, ������ 2��.
//	foo(10);// 3�� ȣ��, ������ 2��.

//	int& r = n;
//	foo(r); // 1�� ȣ��, ������ 2��

	int&& r2 = 10; // �� ���� r2 �޸𸮸� ��� 10�� ����Ų��.
					// 10�� rvalue���� r2��� �̸��� �ְ�
					// ���ʿ� �ü��ִ�. ���� lvalue �̴�.

	//10 = 20; // ����. 10�� rvalue �̴�. ���̴�.
	//r2 = 20; // ok

	foo(r2); // 1�� �θ���.

	foo(static_cast<int&&>(r2)); // 3������ ����. ���� ���¼ҽ��� �ʼ��� �˾ƾ� �Ѵ�.

	r2 = static_cast<int&&>(r2);
	foo(r2); // 1�� �θ���.
}