#include <iostream>

struct Test
{
	int data;

	void foo() &  { std::cout << __FUNCSIG__ << std::endl; }
	void foo() && { std::cout << __FUNCSIG__ << std::endl; }
	void Ǫ() & { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	Test t; // �̸��� �ֽ��ϴ�. ���� ��� ������ ����.
			// �̸��� ���ؼ� ������ ���ٰ���. lvalue
	t.foo();
	t.data = 999;

	Test(); // �̸��� �����ϴ�. ���Ϲ��忡���� ���. rvalue �̸�, 
			// �����ݷ��� ������ ����ı�. �ӽð�ü.
	
	// Test().data = 10; // �ӽð�ü�� ���� �־���� �ٷ� �����ϱ� ������. �׷��� rvalue ���

	Test().foo();

	Test&& r = Test();
	r.foo();

}
