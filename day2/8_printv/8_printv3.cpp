#include <iostream>
#include <type_traits>

// ��� 3. constexpr - cpp17 style
// cppreference.com ���� invoke ã�ƺ���
// possible implementation �����ϱ�

template<typename T>
void printv(T v)
{
	if constexpr (std::is_pointer<T>::value) {
		std::cout << v << " : " << *v << std::endl;
	}
	else {
		std::cout << v << std::endl;
	}	
}
int main()
{
	std::cout << "cpp 17 style! \n";
	int n = 0;
	printv(n);
	printv(&n);
}
