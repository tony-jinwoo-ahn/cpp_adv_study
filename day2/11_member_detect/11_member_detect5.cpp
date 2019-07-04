#include <iostream>

struct Point
{
	int x;
	int y;
};
int main()
{
	int n = 0;
	int* p1 = &n;
//	int* p2 = &Point::y; // error

	//int Point::*  의미: Point 클래스 안에있는 int의 주소
	int Point::*p2 = &Point::y; // ok. 멤버의 주소.
								// pointer to member 기법.

	// 이 코드 어디에서도 Point 객체를 메모리에 만든적이 없다.
	std::cout << p2 << std::endl; // offset_of 기법. 4가 나와야 하는데 cout 한계로 1이 나옴.
	printf("%d\n", p2); // 정확한 오프셋 나옴.

	Point pt;
	pt.*p2 = 10; // 결국 p2.y = 10 과 같은 의미.
				// .* : pointer to member operator
	printf("%d\n", p2); // 정확한 오프셋 나옴.

	p2 = &Point::x;
	printf("%d\n", p2); // 정확한 오프셋 나옴.

	

}
