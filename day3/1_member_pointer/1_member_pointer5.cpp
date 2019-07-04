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
	
	// �Ʒ� �ڵ带 ������ ������
	void* p1 = &n;
	void* p2 = &foo;
	//void* p3 = &Dialog::color; // ����� �ּҸ� ������ ����. �����ּҰ� �ƴ϶� �������̴�.
	//void* p4 = &Dialog:Close; // error

	// ��� �����غ�����
	goo(&n);
	goo(&foo);
	goo(&Dialog::color);
	printf("%d \n", &Dialog::color);
	if (&Dialog::color) std::cout << "true" << std::endl;
	bool bb = &Dialog::color;
	std::cout << bb << std::endl;

	goo(&Dialog::Close);

	std::cout << &n << std::endl;				// cout.operator<<(void*)
	std::cout << &Dialog::Close << std::endl;	// cout.operator<<(bool) // ù���������� cout �ϸ� �̻��ϰ� �����°��� ����.

}
