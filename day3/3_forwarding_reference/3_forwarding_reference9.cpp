#include <iostream>

template<typename T>
class Test
{
public:
	// �Ʒ� �ڵ�� forwarding reference�ϱ��? 
	// NO.
	// Ŭ������ ���ø�����, �Լ��� ���ø��� �ƴϴ�. �ᱹ int&&�� �� ���̴�.
	// Ŭ���� ������ �̹� T�� Ÿ���� �����ȴ�.
	void foo(T&& arg) {} 
	
	// �Ʒ� �ڵ尡 forwarding reference �Դϴ�.
	template<typename U> // ���ο� Ÿ�� U�� ����� ��.
	void goo(U&& arg) {} // ��� Ÿ���� �� ���Ƶ��� �� �ִ�.	
};

int main()
{
	int n = 0;
	Test<int> t;
	t.foo(10);
	t.foo(n);
}