// 1_checked_delete - 37 page
#include <iostream>

// static_assert 는 최대한 많이 사용하자
// 	std::default_delete<int> df; 정의를 참고하자

/*
void operator()(_Ty * _Ptr) const noexcept
		{	// delete a pointer
		static_assert(0 < sizeof (_Ty),
			"can't delete an incomplete type");
		delete _Ptr;
		}
*/

class Test; // class의 전방 선언
			// 완전한 선언이 없어도 포인터 변수는 만들 수 있다.
			// incomplete type (불완전한 타입)

// check 후에 delete 하자! 
void foo(Test* p)
{
//	sizeof(Test); // complete type만 크기를 구할 수 있다. -> 컴파일러가 최적화하느라 이거 지우기도 함
	// 못 지우게 하려면?
	// 안드로이드 소스의 예전 버전에서 볼 수 있었던 코드
	//enum { type_must_be_complete = sizeof(Test) };

	// cpp11 이후에는 static assert 사용
	static_assert(sizeof(Test) > 0, "error: delete incomplete type");

	delete p; // 소멸자가 안 불린다!
}

class Test
{
public:
	Test() { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
};


int main()
{
	std::default_delete<int> df;
	Test* p = new Test;
	foo(p);
}
