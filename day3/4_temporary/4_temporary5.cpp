#include <iostream>
using namespace std;

struct Base
{
	int value = 10;
};
struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;
	std::cout << d.value << endl; //20
	std::cout << static_cast<Base>(d).value << endl;//10 // �̰��� ����� �ӽð�ü �������.
	std::cout << static_cast<Base&>(d).value << endl;//10 // �����̱� ������ �ӽð�ü�� �ȸ������.
	
//	static_cast<Base>(d).value = 100; // error
	static_cast<Base&>(d).value = 100;

	// �� ĳ����: �ӽð�ü ����
	// ���� ĳ����: �ӽð�ü ���� ����.

	std::cout << static_cast<Base&>(d).value << endl;//10 // �����̱� ������ �ӽð�ü�� �ȸ������.

	// ù�� ��������,
	// �ּ� �����ϴ°Ÿ� �ٸ� Ÿ������ ĳ������ ��, ���� �� ĳ������������. <char> �̷��� �ϸ� ���Ѵ�.
	//�ּҸ� ���غ��� ���θ��� �ӽð�ü�� �ּҸ� ���ؿû��̴�.
	// <char&> �̷��� ������ �ؾ� �Ѵ�.
}