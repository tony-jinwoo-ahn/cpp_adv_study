// 6_bind4
#include <iostream>
#include <functional>
using namespace std::placeholders;

class Button
{
public:
//	void(*handler)();
	std::function<void()> handler;
	void Click() { handler(); }
};
void foo() { std::cout << "foo" << std::endl; }
void goo() { std::cout << "goo" << std::endl; }
void hoo(int id) { std::cout << "hoo : " << id << std::endl; }

int main()
{
	Button b1, b2;
//	b1.handler = &foo;
//	b2.handler = &goo;

	// nana cpp gui library
//	Form rm;
//	b1.handler = [&rm]() { rm.Close(); };
	// �Լ� �����ʹ� ĸó�ѰŴ� �� �޴´�. �׷��� function���� �޾ƾ� �Ѵ�.

	b1.handler =
		[]() {std::cout << "dialog close" << std::endl; };

//	b1.handler = std::bind(&hoo, 1);
	b2.handler = std::bind(&hoo, 2);

	b1.Click();
	b2.Click();
}
