#include <iostream>
#include <type_traits>
/*
template <typename T> T gcd(T arg1, T arg2)
{
	// �ִ������� ��ȯ�Ѵٰ� ����.
	// ������ �ƴѰ�� �����ϰ� �ϰ�ʹ�.
	// static_assert : 1��° ���ڰ� false�̸� ������ ����
	static_assert(std::is_integral<T>::value, "not integral");

	return 0;
}
*/

// static_assert: ������ ���� ���ϸ� ������ ����.
// enable_if:     ������ ���� ���ϸ� ���ø� ������� ����.
//	   			  ���� �̸��� �ٸ� �Լ��� ������ ��밡��.

template <typename T> 
typename std::enable_if<std::is_integral<T>::value, T>::type
gcd(T arg1, T arg2)
{
	std::cout << "T.T" << std::endl;
	return 0;
}

// double ������ �Լ� �����Ѵ�ġ��
double gcd(double arg1, double arg2)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(10, 6);
	gcd(3.4, 2.4);
}