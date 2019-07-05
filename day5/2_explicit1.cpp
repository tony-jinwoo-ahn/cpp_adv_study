// 2_explicit
#include <iostream>

class Vector
{
public:
	// explicit 생성자 : 복사 초기화를 사용할 수 없다.
	//					직접 초기화만 가능하다.
	explicit Vector(int size) {}
	// 생성자 만들 때 가급적 explicit 사용하라
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
