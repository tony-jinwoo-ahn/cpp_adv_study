// 2_explicit
#include <iostream>

class Vector
{
public:
	// explicit ������ : ���� �ʱ�ȭ�� ����� �� ����.
	//					���� �ʱ�ȭ�� �����ϴ�.
	explicit Vector(int size) {}
	// ������ ���� �� ������ explicit ����϶�
};

void foo(Vector v) {} // Vector v = 10
					// Vector v = v1

int main()
{
	Vector v1(10); // direct initialization
//	Vector v2 = 10;// copy initialization
	Vector v3{ 10 }; // direct initialization

	foo(v1); // ok
//	foo(10); // ??? // Vector v = 10
}
