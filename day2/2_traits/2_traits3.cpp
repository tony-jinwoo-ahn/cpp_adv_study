// 2 traits 
// 115 page int-to-type ���ó���
#include <iostream>
using namespace std;

// is_reference ������


// ����� ��
// 1. ����ü ���ø��� �����.
// 2. enum { value = false } �� �ִ´�.
// 3. ������ �����ϴ� �κ� Ư��ȭ ������ �����.
//		�׸��� enum { value = true } �� �ִ´�.

template<typename T> struct is_ref
{
	enum { value = false };
};
template<typename T> struct is_ref<T&>
{
	enum { value = true };
};
template<typename T> struct is_ref<T&&>
{
	enum { value = true };
};

template<typename T> struct is_const2<T>
{
	enum { value = false };
};
template<typename T> struct is_const2<const T>
{
	enum { value = true };
};


template<typename T>
int is_reference2(T v)
{
	if (is_ref<T>::value) {
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	cout << is_ref<int>::value << endl;
	cout << is_ref<int&>::value << endl;

}