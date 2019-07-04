#include <vector>
#include <iostream>

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
int main()
{
	std::vector<Test> v;
	v.reserve(10); // memory 미리 확보 
	Test data;

	v.push_back(data); // copy
	v.push_back(std::move(data)); // 자원 이동
}