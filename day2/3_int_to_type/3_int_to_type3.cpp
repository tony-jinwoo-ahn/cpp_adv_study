#include <iostream>
#include <type_traits>

// �������� ���� �ƴѰ��� �и��ؼ� 2���� �Լ� template�� �����.

template <typename T> void printv_imp_pointer(T v)
{
	std::cout << "pointer" << std::endl;
	std::cout << v << " : " << *v << std::endl;
}
/*
template <typename T> void printv_imp_pointer(T v)
{
	std::cout << "Not pointer" << std::endl;
	std::cout << v << std::endl;
}
*/

template <typename T> void printv_imp_not_pointer(T v)
{
	std::cout << "Not pointer" << std::endl;
	std::cout << v << std::endl;
}

template <typename T> void printv(T a)
{
	// if��: ����ð� ���ǹ�
	//		 ������ ����� ������� �������� ����
	//		 �Ʒ� 2���� �Լ� ���ø� ��� ���ȴٰ� 
	//		 �����Ϸ��� �����ؼ� 2�� �Լ� ��� �ν��Ͻ�ȭ��.
	if (std::is_pointer<T>::value)
		printv_imp_pointer(a);
	else
		printv_imp_not_pointer(a);
}
int main()
{
	int n = 0;
	printv(n);
	printv(&n);
}
