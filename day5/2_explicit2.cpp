#include <iostream>
#include <string>
#include <vector>
#include <memory>

void foo(std::string s) {}

int main()
{
	// string은 explicit 생성자가 아닙니다.
	std::string s1("hello");
	std::string s2 = "hello"; // ok.
	// foo("hello"); // explicit 생성자라면 error

	// vector의 생성자는 explicit 입니다
	std::vector<int> v1(10); // 10개짜리 벡터. 크기를 나타냄.
	std::vector<int> v2 = 10; // 이거 error
	std::vector<int> v3{ 10 }; // 1개짜리 벡터인데 초기값이 10이다.
	std::vector<int> v4 = { 10 }; // ??? ok. 1개를 초기화한거다. explicit 아님.

	// cpp 표준 스마트포인터는 모두 explicit
	std::unique_ptr<int> p1(new int);
	std::unique_ptr<int> p2 = new int; // error
}
