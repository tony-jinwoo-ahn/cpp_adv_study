#include <iostream>
#include <string>


class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {}
	~Test() {}
	// move 생성자에서는 모든 멤버를 반드시 move로 옮기자!
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
