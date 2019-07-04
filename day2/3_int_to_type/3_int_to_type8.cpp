#include <iostream>
#include <type_traits>
using namespace std;

//  ������ ���ο� ���� �ٸ��� ó���ϴ� ���

// 1. cpp17 �� ������ ������.
template<typename T> void foo_imp(T v, true_type) {}
template<typename T> void foo_imp(T v, false_type) {}

/*
template<typename T> void foo(T v)
{
	//1. is_pointer<T>::value ���
	if (std::is_pointer<T>::value)
	{
		// ��, �Ʒ��� ���� ǥ������ ���Ұ�.
		*v = 10; // error. if�� ���ΰ� ������ �Ǵ��� ������ �ǹǷ�.
	}
	else
	{
	}
	// 2. true_type / false_type ����� �����ε�
	// foo_imp �ȿ����� *v = 10 ��밡��.
	foo_imp(v, is_pointer<T>());

}
*/

// 2. enable_if ���
// ���� ���...

// 3. cpp17 ���Ŀ��� true_type, false_type ���󵵵�! constexpr �����.
// /std:c++17
// g++ : g++ �ҽ��̸�.cpp -std=c++17
template<typename T> void foo(T v)
{
	// if constexpr : �����Ͻð� if��
	// ������ ������ ��� �ڵ� ��ü�� �������� �ʴ´�.
	if constexpr (std::is_pointer<T>::value)
	{
		//*v = 10;
		std::cout << v << " : " << *v << std::endl;
	}
	else
	{
		std::cout << v << std::endl;
	}
}

int main()
{
	int n = 999;
	foo(n);
	foo(&n);
}
