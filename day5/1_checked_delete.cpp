// 1_checked_delete - 37 page
#include <iostream>

// static_assert �� �ִ��� ���� �������
// 	std::default_delete<int> df; ���Ǹ� ��������

/*
void operator()(_Ty * _Ptr) const noexcept
		{	// delete a pointer
		static_assert(0 < sizeof (_Ty),
			"can't delete an incomplete type");
		delete _Ptr;
		}
*/

class Test; // class�� ���� ����
			// ������ ������ ��� ������ ������ ���� �� �ִ�.
			// incomplete type (�ҿ����� Ÿ��)

// check �Ŀ� delete ����! 
void foo(Test* p)
{
//	sizeof(Test); // complete type�� ũ�⸦ ���� �� �ִ�. -> �����Ϸ��� ����ȭ�ϴ��� �̰� ����⵵ ��
	// �� ����� �Ϸ���?
	// �ȵ���̵� �ҽ��� ���� �������� �� �� �־��� �ڵ�
	//enum { type_must_be_complete = sizeof(Test) };

	// cpp11 ���Ŀ��� static assert ���
	static_assert(sizeof(Test) > 0, "error: delete incomplete type");

	delete p; // �Ҹ��ڰ� �� �Ҹ���!
}

class Test
{
public:
	Test() { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }
};


int main()
{
	std::default_delete<int> df;
	Test* p = new Test;
	foo(p);
}
