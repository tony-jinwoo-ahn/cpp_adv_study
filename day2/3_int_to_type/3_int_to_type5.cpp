// 0�� 1�� ��� �ٸ� Ÿ������ ���� �����ε��� ������ų��?

#include <iostream>
#include <type_traits>

// ���ø� ���ڷδ� Ÿ�Ի� �ƴ϶� ������ �������� ����. 
// 115 page code
template<int N> struct my_int2type
{
	enum {value = N};
};

int main()
{
	foo(0);
	foo(1); // 0, 1�� ���� Ÿ��. foo(0), foo(1)�� ���� �Լ� ȣ��.
	my_int2type<0> t0; // ����ü�� 0�� �� Ÿ��.
	my_int2type<1> t1; // ����ü�� 1�� �� Ÿ��. ���� �ٸ� Ÿ���� �Ǿ���.
	foo(t0); 
	foo(t1); // t0, t1�� �ٸ� Ÿ��. foo(t0), foo(t1)�� �ٸ� �Լ� ȣ��.
}

// int to type ���п� ���ڸ� ������ �Լ� �����ε��� �ȴ�.
