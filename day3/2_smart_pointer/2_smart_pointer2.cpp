// 2_스마트포인터_2
#include <iostream>
#include <memory>

struct Point
{
	int x, y;
	Point(int a=0, int b=0) : x(a), y(b) {}
};
// 메모리할당에 사용되는 operator new() 함수를 재정의할 수 있습니다.
void* operator new(size_t sz)
{
	std::cout << "new: " << sz << std::endl;
	return malloc(sz);
}

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요?
	//std::shared_ptr<Point> sp(new Point);
	// Point 객체 할당
	// 관리객체 할당
	// 총 2번.
	// sp는 위 둘을 가리킨다.
	// 작은 객체들이 메모리에 여기저기 떨어져있으면 조각나서 성능 저하.
	// 관리객체를 옆에 붙이자. 따로따로 만들지 말자.
	
	// sizeof(Point) + sizeof(관리객체)를 한번에 메모리 할당. 
	// 스마트 포인터를 쓸 때는 항상 이렇게 하자.
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
}

// make_shared 의 원리
template <typename T, typename ... Types>
std::shared_ptr<T>
make_shared2(Types&& ... args)
{
	// 1. memory alloc
	// 한번에 두 크기를 합친 영역을 할당해야 하는데, 이건 new로는 못한다.
	void* p = operator new(sizeof(T) + sizeof(12));
		// 관리객체의 크기를 12라고 가정.

	// 2. 메모리 위쪽에 놓인 객체에 대해서 생성자 호출
	new(p) T(std::forward<Types> (args) ...); // cpp11 완벽한전달

	// 3. 관리 객체 초기화

	// 4. shared_ptr을 만들어서 반환
	char* p2 = static_cast<char*>(p);
	std::shared_ptr<T> sp;
	sp.reset(static_cast<T*>(p2), // 객체 주소
		p2 + sizeof(T));		  // 관리객체 주소

	return sp;
}
