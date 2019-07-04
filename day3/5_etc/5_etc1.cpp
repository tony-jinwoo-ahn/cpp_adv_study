//참고
#include <iostream>

template<typename T> class Base
{
public:
	//virtual void foo(const T a) // 이렇게 적으면 T가 (int*)로 변환될 경우 const int* a 가 되어 혼동의 시작.
	virtual void foo(T const a) // 이렇게 적으면 가독성이 높아지고 실수할 일이 없다. const를 뒤에 적자.
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Derived : public Base<int*>
{
public:
	// foo 가상함수 재정의 해보세요. override 사용하지 말아봐.
	//virtual void foo(const int* a) //별을 기점으로 왼쪽에 const int가 있으므로: 나를 따라가면 const가 있다라는 의미. a를 따라가면 const라는 의미가 되어버림.
									// 이건 가상함수를 재정의한게 아니고 전혀 다른걸 만든거다.
									// override를 붙였으면 컴파일러가 알려줬겠지. 그래서 override 쓰는게 좋은거다.

	virtual void foo(int* const a) // 별을 기점으로 const가 a쪽에 붙었으므로: a가 const이다.
	{
		std::cout << "Derived foo" << std::endl;
	}

};
int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" 나오게 해보세요.
}
