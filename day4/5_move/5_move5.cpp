#include <iostream>
#include <string>

// 클래스가 자원을 할당하지 않으면 - 소멸자가 없어도 된다.
// 클래스가 자원을 할당하면
// C++98
// "소멸자", "복사생성자", "대입연산자"가 필요하다. - rule of 3
// C++11 부터는 2개 추가
// rule of 3 +
// "move 생성자", "move 대입연산자" - rule of 5

// move 계열함수를 제공하지 않으면
// "복사 계열 함수가 호출되게 된다."

class Test
{
	int data;
	int* resource;
public:

	Test() {} // resource = new int
	~Test() {}
	Test(const Test& t) {
		std::cout << __FUNCSIG__ << std::endl;
	}
	Test& operator=(const Test& t) { return *this; }

	Test(Test&& t) {}
	Test& operator=(Test&& t) { return *this; }
};

int main()
{
	Test t1;
	Test t2 = t1;
	t2 = t1;

	Test t3 = std::move(t1); // static_cast<Test&&>(t1)
	t3 = std::move(t1);
}
