// 2 traits 
// 115 page int-to-type 관련내용
#include <iostream>
using namespace std;
// Traits: 템플릿 인자 T의 다양한 특질(traits)을 조사하는 기술.
// 이놈이 포인터인지 가상함수인지 클래스인지 등등 조사.
template<typename T> void printv(T v)
{
	if (T is pointer) {
		std::cout << v << " : " << *v << std::endl;
	}
	else
	{
		std::count << v << std::endl;
	}	
}
int main()
{
	int n = 10;
	printv(n);
	printv(&n);

}
