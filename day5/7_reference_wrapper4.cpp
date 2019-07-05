#include <iostream>
#include <functional>
#include <thread>

void foo(int a, int& b) { b = 100; }

int main()
{
	int n = 0;
//	std::thread t(&foo, 1, n); // thread 의 생성자에서 스레드 생성
								// 즉, 이 순간 스레드가 생성됩니다.
	
	std::thread t(&foo, 1, std::ref(n));
	// n이 지역변수인데 스레드에 참조로 넘어가면 지역변수는 파괴되는데 스레드는 계속 살아있으면 어떡하냐
	// 그래서 ref() 쓸 때는 조심해야 한다
	
	t.join();
	std::cout << n << std::endl; // ???
}
