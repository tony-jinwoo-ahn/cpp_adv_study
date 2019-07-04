//#include <iostream>

/*
// 함수객체의 2가지 장점 요약:
1. 상태를 갖는다
2. 인라인 치환성을 갖는다
*/


// 1. inline 함수는 컴파일 할 때 이루어진다. 실행안하고 치환만 한다.

// 함수객체의 장점 2.
// 다른 함수의 인자로 전달되는 함수를 만들 때
// 1. 일반 함수를 보내면 다시 호출시 인라인 치환되지 못한다.
// 2. 함수 객체를 보내면 다시 호출시 인라인 치환된다.


inline int Add(int a, int b) { 
//	std::cout << a + b << std::endl;
	return a + b; 
}
struct Plus
{
	inline int operator() (int a, int b) { return a + b; }
};

template<typename T> void foo(T f) // 일반함수 쓰지마. 함수객체 보내는게 훨씬 빠르다.
{
//	std::cout << __FUNCSIG__ << std::endl;
	int n = f(1, 2); // 이 순간을 잘 생각해 보세요. inline 치환 불가. 함수포인터 받으면 주소밖에 모르는데 치환을 어케하겠음.
	// f.operator()(1,2)
}
int main()
{
	Plus p;
	foo(Add); // 함수 포인터 전달(int (*f)(int, int)) // 주소만 알수있을뿐, 얘가 누군지는 모른다.
	foo(p);// Plus 타입으로 전달 // 아 얘가 Plus구나 정확히 알수있음.

	/*
	// 단점은 없을까? Sub 를 받았다고 치자.
	foo(Add); // 함수 포인터 전달(int (*f)(int, int)) 
	foo(Sub); // 함수 포인터 전달(int (*f)(int, int))
	// 둘다 똑같은 모양이 된다.
	*/

	/*
	foo(p); // Plus 타입으로 전달 foo(Plus f) // 컴파일러가 이 f가 무슨 타입인지 정확히 알수있어서 치환 가능.
	Minus m;
	foo(m); // foo(Minus)
	// 이렇게 함수가 하나 더 생기는 문제가 있음.
	*/

}


