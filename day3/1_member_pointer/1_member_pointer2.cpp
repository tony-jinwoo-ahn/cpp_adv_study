#include <iostream>
#include <Windows.h>

/*
// C 언어 스타일
DWORD __stdcall foo(void* p) // void 포인터를 반드시 받아야 함
{
	return 0;
}
*/

// 스레드 개념을 담은 클래스
// 아래 코드를 라이브러리 내부 클래스라고 생각하세요
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }
	/*
	DWORD __stdcall threadMain(void* p) // 이 안에 this가 있기 때문에 에러! void*만 있어야 한다. 
		//그래서 멤버함수면 안된다. 
		//핵심: 이 함수는 반드시 static이 되어야 한다. 
		//그래야 파라미터에 암시적으로 들어가는 this 를 제거한다.
	{
		threadLoop();
		return 0;
	}
	*/
	/*
	static DWORD __stdcall threadMain(void* p) // 이 안에는 this가 없지만, 위에서 파라미터로 this를 넘겨줘서 받는다.
	{
		threadLoop(); // 이번엔 이게 에러난다. static이 되고나니까 멤버데이터, 멤버함수 사용불가해진다.
		return 0;
	}
	*/

	// 안드로이드소스/platform_system_core/libutils/include/utils/Thread.h 참고!
	//https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/Thread.h
	//platform_system_core/libutils/Threads.cpp 참고
	//https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/Threads.cpp
	//https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/Threads.cpp#L713

	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// self가 결국 this 입니다.
		// self를 사용하면 static 멤버함수에서도 다른멤버에 접근 가능.
		self->threadLoop();
		//threadLoop();
		return 0;
	}

	virtual void threadLoop() = 0;
};
// 아래 클래스는 사용자 클래스입니다
class MyThread : public Thread
{
public:
	virtual void threadLoop()
	{
		std::cout << "MyThread" << std::endl;
	}
};
int main()
{
//	CreateThread(0, 0, foo, "A", 0, 0); // win32 thread function
	// linux: pthread_create(...)

	MyThread mt;
	mt.run(); // 이 순간 새로운 스레드가 생성되어서 threadLoop() 를 
				// 실행해야 합니다.
	getchar();

}