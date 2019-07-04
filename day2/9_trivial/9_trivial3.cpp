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
		// 복사생성자가 하는일이 있으면 각 요소에 대해
		// 복사생성자 호출.
		while (n--) {
//			new T; // 메모리할당 + 생성자호출
//			new T(*s); // 메모리할당 + 복사생성자 호출
//			new(d) T; // d 메모리에 디폴트 생성자 호출
			
			new(d) T(*s); // d 메모리에 복사생성자 호출
			++d, ++s;
		}
	}	
}
// -> 이제 enable_if 버전으로 만들어보기!
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

	//strcpy(s2, s1); // 메모리 할당이 없고, 기존 메모리 복사

	copy_type(s2, s1, 10); // Let's make!

}