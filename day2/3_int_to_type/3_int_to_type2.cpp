#include <iostream>
#include <type_traits>

template <typename T> void printv(T a)
{
	if ( std::is_pointer<T>::value ) // 컴파일할 때 알 수 있다.  if ( false ) { 
		std::cout << a << " : " << *a << std::endl; // 그러나 if문 본연의 기능은 런타임 검사이므로, 이 line을 일단 검사한 결과, int 역참조 에러발생.
	else
		std::cout << a << std::endl;
}
int main()
{
	int n = 0;
	printv(n);
//	printv(&n);
}
