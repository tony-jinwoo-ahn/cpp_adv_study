#include <iostream>
#include <type_traits>

template <typename T> void printv(T a)
{
	if ( std::is_pointer<T>::value ) // �������� �� �� �� �ִ�.  if ( false ) { 
		std::cout << a << " : " << *a << std::endl; // �׷��� if�� ������ ����� ��Ÿ�� �˻��̹Ƿ�, �� line�� �ϴ� �˻��� ���, int ������ �����߻�.
	else
		std::cout << a << std::endl;
}
int main()
{
	int n = 0;
	printv(n);
//	printv(&n);
}
