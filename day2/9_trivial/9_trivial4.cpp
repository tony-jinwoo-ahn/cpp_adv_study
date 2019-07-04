#include <iostream>
#include <atomic>
#define _ENABLE_ATOMIC_ALIGNMENT_FIX


struct Point
{
	int x, y, z;
	Point() {}

	// 사용자가 제공한 복사 생성자
	Point(const Point& p) : x(p.x), y(p.y), z(p.z) {} 
	
};
std::atomic<int> an;
std::atomic<Point> ap;
// 복사생성자가 하는일이 없어야 atomic 쓸수있다. 
// trivial 해야 한다.
// 내부적으로 static_assert 써서 trivial 한지를 체크하고 있을듯.

int main()
{
	int n = an.load(); // multi thread에 안전하게 load.

	Point pt = ap.load(); // 멀티스레드에 안전. 하지만 lock free가 아닌
						// 내부적인 동기화 기법을 사용함.
						// 대부분 "busy waiting" 합니다.

	std::cout << an.is_lock_free() << std::endl;
	std::cout << ap.is_lock_free() << std::endl;

	/*
	// n = n+1의 어셈
	__asm
	{
		mov eax, n
		add eax, 1
		mov n, eax
	}
	// 멀티스레드에 안전하게 1 증가
	// 인텔 계열 cpu는 lock prefix 사용
	__asm
	{
		lock inc n // 하나의 cpu가 사용할 때 다른 cpu가 절대 사용 불가. 
		// 운영체제의 락이 아님. lock free 기법. OS의 lock을 사용하지 않는다는 의미.
		// cpu의 락을 쓰는거임.
	}
	*/

}