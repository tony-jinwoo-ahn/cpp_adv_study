#include <iostream>

void foo(int&  arg) { std::cout << __FUNCSIG__ << std::endl; }
void foo(int&& arg) { std::cout << __FUNCSIG__ << std::endl; }

void forwarding(int&  n) { foo(n); }
void forwarding(int&& n) {
	// main���� 10(rvalue)�� ���´µ�
	// int&& n = 10 ���� �����鼭 lvalue �� �Ǿ���.
	// ��, value�� Ư���� ����Ǿ���.
	// ������� (rvalue��) ĳ�����ؼ� ����
	foo(static_cast<int&&>(n));
	// �� ĳ������ �־�� �Ϻ��� �������� �ȴ�. (perfect forwarding)

}


int main()
{
	int x = 10;
	forwarding(x); // x�� foo�� ������ �ʹ�
	forwarding(10);// 10�� foo�� ��������

	int&& n = 10; // 10 : rvalue
				  //  n : lvalue (�̸��� �����ϱ�.)


}
