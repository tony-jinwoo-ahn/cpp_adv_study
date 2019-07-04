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
	std::cout << static_cast<Base>(d).value << endl;//10 // 이거의 결과로 임시객체 만들어짐.
	std::cout << static_cast<Base&>(d).value << endl;//10 // 참조이기 때문에 임시객체는 안만들어짐.
	
//	static_cast<Base>(d).value = 100; // error
	static_cast<Base&>(d).value = 100;

	// 값 캐스팅: 임시객체 생성
	// 참조 캐스팅: 임시객체 생성 안함.

	std::cout << static_cast<Base&>(d).value << endl;//10 // 참조이기 때문에 임시객체는 안만들어짐.

	// 첫날 수업에서,
	// 주소 못구하는거를 다른 타입으로 캐스팅할 때, 절대 값 캐스팅하지마라. <char> 이렇게 하면 망한다.
	//주소를 구해봤자 새로만든 임시객체의 주소를 구해올뿐이다.
	// <char&> 이렇게 참조로 해야 한다.
}