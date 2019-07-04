#include <iostream>

// 핵심1. 일반 함수 포인터에 멤버 함수의 주소를 넣을 수 없다.
//     2. 일반함수 포인터에 static 멤버함수의 주소는 넣을 수 있다.

class Dialog
{
public:
	void Close() // void Close(Dialog* this)
	{ std::cout << "Close" << std::endl; }

	static void Close2() {}
};
void foo() { std::cout << "foo" << std::endl; }

int main()
{
	void(*f1)() = &foo;
//	void(*f2)() = &Dialog::Close; // 에러. 멤버함수	
	void(*f3)() = &Dialog::Close2;

	// 멤버 함수를 가리키는 포인터 변수 만드는 모양
	// pointer to member
	void(Dialog::*f2)() = &Dialog::Close; // 이렇게 하면 해결.

	//f2(); 객체가 없어서 에러남.
	
	Dialog dlg;
	//dlg.f2(); // 이 객체에서 f2라는 함수를 찾게 되므로 에러.
	//dlg.*f2 (); // .* : pointer to member operator // 연산자 우선순위 때문에 괄호가 먼저 해석되어서 또 에러남
	(dlg.*f2) (); // 괄호로 연산자 우선순위를 높여야 한다.
	((&dlg)->*f2) (); // 이거도 가능.
	// 즉, pointer to member operator 는 2개의 형태가 가능.
	// .*
	// ->*

	// 근데 이렇게 하면 가독성도 떨어지고 함수는 보통 f() 형태라서 그런 모양을 맞추고 싶다
	// invoke: cpp 17 에서 추가
	std::invoke(f1); // f1 함수 호출 
					 // 내부적으로 멤버함수인지 일반함수인지 조사. std::is_member_function_pointer_v
	// invoke(f1, 10, 20); f1(10, 20)

	std::invoke(f2, &dlg); // (dlg.*f2)() 의 의미
	//invoke(f2, &dlg, 10, 20); // (dlg.*f2)(10,20); 라는 의미
}
