// lvalue, rvalue 모두 전달받는 함수 만들기!

#include <iostream>

// 함수 인자로
// int&  : int의 lvalue만 전달 가능.
// int&& : int의 rvalue만 전달 가능.
// T&    : 모든 타입의 lvalue만 전달 가능.

// T&&   : 모든 타입의 lvalue와 rvalue 전달 가능.

// lvalue(n) 을 보내면 T : int& 이고, 함수 최종버전은 (int&) 이다.
// rvalue(0) 을 보내면 T : int  이고, 함수 최종버전은 (int&&)이다.

//***************************************************

// lvalue, rvalue 모두 전달받는 함수 만들기!
// 1. 콜 바이 value 
// lvalue, rvalue 다 받지만, 원본이 아닌 복사본. 덩치가 커지면 느려짐
void f1(int  a) {}

// 2. const lvalue reference
// 일반 참조는 lvalue만 받을 수 있으므로, const 붙인다.
void f2(const int& a) {} // const 때문에 값을 바꿀 수 없는 단점.

// 3. 2개의 함수
void f3(int&  a) {}
void f3(int&& a) {} // 하는일이 비슷한 함수를 매번 2개 만들어야 하는 단점.

// 4. 2개의 함수를 자동생성
// T&&   : forwarding reference (=universal reference) => 참조변수를 안고 있을 수 있다.
// int&& : rvalue reference (정확한 데이터 타입이 정해짐. 더이상 참조변수를 껴안고 있을 여지가 없다.)
template<typename T> 
void f4 (T&& a) {
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 0;
	f4(n); // T: ?  f1(?) 어떻게 나올지를 외워야 한다. 암기하자! 컴파일러가 어떻게 결정하는지를.
	f4(10);

	/*
	f4<int>(0); //  T : int   이고  T&& : int&&  이니까     f4(int&&)
	f4<int&>(n); // T : int&  이고  T&& : int& && 이니까    f4(int&)
	f4<int&&>(0);// T : int&& 이고  T&& : int&& &&  이니까  f4(int&&)
	*/
}

// forwarding reference 는 인자를 literal도 받고 아닌거도 받고 다 받겠다는거다.
// 이게 나오기 전에는 const 붙은버전을 썼었다.
