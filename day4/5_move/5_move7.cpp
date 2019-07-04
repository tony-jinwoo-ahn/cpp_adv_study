#include <iostream>
#include <string>
#include <vector>


class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {}
	~Test() {}	
	Test(const Test& t) : data(std::move(t.data)), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	Test& operator=(const Test& t) {
		data = t.data;
		s = std::move(t.s);

		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}

	// move와 예외
	// move 계열 함수를 만들 때는 예외가 나오지 않게 만들고
	// 예외가 없다고 꼭 컴파일러에게 알려주자
	// noexcept : 예외가 없다는 의미
	// noexcept(true) : 예외가 없다.
	// noexcept(false) : 예외가 있을 수 있다.

	// sizeof(표현식): 표현식 크기
	// decltype(표현식) : 표현식 타입
	// noexcept(표현식) : 표현식의 예외 여부 조사.

	Test(Test&& t) noexcept (
		std::is_nothrow_move_constructible<std::string>::value)
		: data(t.data), s(std::move(t.s)) 
	{
		std::cout << __FUNCSIG__ << std::endl;	
	}

	Test& operator=(Test&& t) noexcept (
		std::is_move_assignable<std::string>::value)
	{
		data = t.data;
		s = std::move(t.s);
		std::cout << __FUNCSIG__ << std::endl;
		return *this; 
	}
};

int main()
{
	Test t1;
	Test t2 = t1;				// 무조건 복사 생성자 사용
	Test t3 = std::move(t2);	// 무조건 move 생성자 사용
								// 예외가 있어도 사용
								// 단지, 캐스팅일 뿐
								// static_cast<Test&&>(t2)

	Test t4 = std::move_if_noexcept(t3);
								// move 생성자의 예외 여부 조사
								// 예외가 없으면 move 사용
								// 있으면 복사 생성자 사용

}

// noexcept 지시어 : 함수가 예외가 없음(있음)을 알리는 것
// void foo() noexcept
// void foo() noexcept(true)
// void foo() noexcept(false)

// noexcept 연산자 : 표현식이 예외가 있는지 조사하는 것
// bool b = noexcept(foo())
// bool b = noexcept(T())
