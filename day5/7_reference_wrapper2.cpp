// 7_reference_wrapper
#include <iostream>
#include <functional>

// reference_wrapper : �̵� ������ ����
// �������� ���Խ� ������ �̵�

template<typename T> class reference_wrapper
{
	// ������ ���������� �����͸� �����ִ� ���̴�
	T* ptr;
public:
	reference_wrapper(T& p) { ptr = &p; }
	// ��ȯ ������: ��ȯ Ÿ���� ǥ������ �ʴ� Ư¡�� �ִ�.
	// ��ü�� �ٸ� Ÿ������ ��ȯ�Ǳ� ���� �ʿ���.
	operator T&() { return *ptr; }
	T& get() const { return *ptr; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;
	reference_wrapper<int> r1 = n1;
	reference_wrapper<int> r2 = n2;

	int& r3 = r1; // ��¥ ������ ȣȯ �����ؾ� �Ѵ�.
				// r1.operator int&() ��� "��ȯ ������" �Լ��� �ִ��� ã�� �ȴ�.

	r2 = r1; // �� �� ���� �ǹ̸� �� ������ ������ 
	// �̹����� ����Ű�� ����� �ٲ��!

//	r2.get() = 30;

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
}
