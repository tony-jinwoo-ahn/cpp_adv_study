

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


template<typename T> void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);

}

// 1. 사용자가 복사와 move를 모두 제공하지 않으면
// => 컴파일러가 모두 제공해 준다.
// 
// 2. 사용자가 복사 계열함수를 제공하면
//    컴파일러는 move 계열을 제공하지 않는다.
// 결론: 아무것도 만들지 마세요
// rule of 0 : 사용자가 직접 자원을 관리하지 않으면
//             소멸자, 복사계열 2개, move계열 2개를 만들 필요 없다.
//             컴파일러가 모두 제공! 아주 기쁘다!
class Object
{
	Test data;
	//char* s; // 이거 있으면 복사생성자 어쩔수없이 만들어줘야 함. 절대 raw pointer 쓰지마라.
	//std::string s; // 이거 써라! string 이든 vector든 쓰면 된다.
	// 함부로 뭔가를 raw하게 쓰려면 이거저거 완벽하게 다 알아서 만들어줘야 한다. 컴파일러가 알아서 하게 해라.

public:
	Object() {}
	Object(const Object& o) : data(o.data) {}
};

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o2);
}
