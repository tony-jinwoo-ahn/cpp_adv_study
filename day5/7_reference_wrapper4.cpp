#include <iostream>
#include <functional>
#include <thread>

void foo(int a, int& b) { b = 100; }

int main()
{
	int n = 0;
//	std::thread t(&foo, 1, n); // thread �� �����ڿ��� ������ ����
								// ��, �� ���� �����尡 �����˴ϴ�.
	
	std::thread t(&foo, 1, std::ref(n));
	// n�� ���������ε� �����忡 ������ �Ѿ�� ���������� �ı��Ǵµ� ������� ��� ��������� ��ϳ�
	// �׷��� ref() �� ���� �����ؾ� �Ѵ�
	
	t.join();
	std::cout << n << std::endl; // ???
}
