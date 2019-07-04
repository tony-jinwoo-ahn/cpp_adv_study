#include <iostream>

class Dialog
{

public:
	void Close() // void Close(Dialog* this)
	{
		std::cout << "Close" << std::endl;
	}

	static void Close2() {}
	int color;
};
void foo() { std::cout << "foo" << std::endl; }
void goo(void* p) { printf("%p \n", p); }
void goo(bool b) { printf("%d \n", b); }

int main()
{
	int n = 0;
	
	// 아래 코드를 생각해 보세요
	void* p1 = &n;
	void* p2 = &foo;
	//void* p3 = &Dialog::color; // 멤버의 주소를 담을수 없다. 실제주소가 아니라 오프셋이다.
	//void* p4 = &Dialog:Close; // error

	// 결과 예측해보세요
	goo(&n);
	goo(&foo);
	goo(&Dialog::color);
	printf("%d \n", &Dialog::color);
	if (&Dialog::color) std::cout << "true" << std::endl;
	bool bb = &Dialog::color;
	std::cout << bb << std::endl;

	goo(&Dialog::Close);

	std::cout << &n << std::endl;				// cout.operator<<(void*)
	std::cout << &Dialog::Close << std::endl;	// cout.operator<<(bool) // 첫날수업에서 cout 하면 이상하게 나오는거의 이유.

}
