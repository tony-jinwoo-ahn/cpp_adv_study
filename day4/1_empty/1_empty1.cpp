// page 73
#include <iostream>
using namespace std;

// empty class : non static 멤버 데이터가 없는 클래스
struct AAA
{	
};
int main()
{
	AAA aaa;
	std::cout << sizeof(aaa) << std::endl; // 모든 컴파일러에서 크기 1이다. 표준.
}
