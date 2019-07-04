#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;
};
/*
template<typename T>
void
copy_type(T* d, T* s, size_t n)
{
	if (std::is_trivially_copy_constructible<T>::value) {
		memcpy(d, s, sizeof(T)*n);
	}
	else {
		// ��������ڰ� �ϴ����� ������ �� ��ҿ� ����
		// ��������� ȣ��.
		while (n--) {
//			new T; // �޸��Ҵ� + ������ȣ��
//			new T(*s); // �޸��Ҵ� + ��������� ȣ��
//			new(d) T; // d �޸𸮿� ����Ʈ ������ ȣ��
			
			new(d) T(*s); // d �޸𸮿� ��������� ȣ��
			++d, ++s;
		}
	}	
}
// -> ���� enable_if �������� ������!
*/

template<typename T>
typename std::enable_if< 
	std::is_trivially_copy_constructible<T>::value>::type
copy_type(T* d, T* s, size_t n)
{
	memcpy(d, s, sizeof(T)*n);
}

template<typename T>
typename std::enable_if< 
	!std::is_trivially_copy_constructible<T>::value>::type
copy_type(T* d, T* s, size_t n)
{
	while (n--) {
		new(d) T(*s);
		++d, ++s;
	}
}

int main()
{
	char s1[10] = "hello";
	char s2[10];

	//strcpy(s2, s1); // �޸� �Ҵ��� ����, ���� �޸� ����

	copy_type(s2, s1, 10); // Let's make!

}