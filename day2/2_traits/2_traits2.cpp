// 2 traits 
// 115 page int-to-type ���ó���
#include <iostream>
using namespace std;

// is_pointer: �������Ҷ� T�� ���������� �����ϴ� ����.
//				�������Ҷ� ����ϴ� �Լ���� �ǹ̷� meta function �̶� �Ѵ�.

// ����� ��
// 1. ����ü ���ø��� �����.
// 2. enum { value = false } �� �ִ´�.
// 3. ������ �����ϴ� �κ� Ư��ȭ ������ �����.
//		�׸��� enum { value = true } �� �ִ´�.

template<typename T> struct is_pointer2
{
	enum { value = false };
};
// ���ø� �κ� Ư��ȭ(specialization) ����
// T�� ���¿� ���� �ٸ� ������ ����ϰڴٴ� �ǹ�.
template<typename T> struct is_pointer2<T*>
{
	enum { value = true };
};


template<typename T> 
void foo(T v)
{
	
	if (is_pointer2<T>::value) {
		std::cout << "Pointer!" << endl;
	}
	else
	{
		cout << "Not a pointer..." << endl;
	}
	
}


int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}