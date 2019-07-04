#include <iostream>
#include <Windows.h>
#include <memory>

// std::enable_shared_from_this : this 포인터로
//			외부에서 만든 관리객체를 공유할 수 있게 하는 기반 클래스
class Thread : public std::enable_shared_from_this<Thread> // CRTP 기법이다. 기억나나?
{
	std::shared_ptr<Thread> holdme;
public:
	~Thread() { std::cout << "~Thread" << std::endl; }

	// 아래 코드는 2개의 문제가 있습니다. 
	// 1. raw pointer(this)를 가지고 초기화하면
	//		관리객체가 따로 만들어져서 무쓸모.
	// 2. 생성자에서 초기화하면 관리객체를 같이 사용할 때
	//		참조계수가 즉시 2가 됩니다.
	// 3. 생성자가 호출된 시점에는 아직 외부의 sp 스마트 포인터가
	//		초기화되지 않은 시점입니다. 즉, 관리객체가 없습니다.

	//Thread() : holdme(this)

	// shared_from_this() : 외부에 만들어져 있는 shared_ptr 용
	//						관리 객체를 같이 사용하게 하는 함수. 마치 마법같다..
	Thread() // : holdme( shared_from_this() )
	{
		// 이게 호출될 시점에는 아직 sp 가 안만들어져 있는 시점이다.
	}

	void run() { 
		// 여기서 초기화하는게 바람직.
		holdme = shared_from_this(); // 이 순간 외부의 sp의 관리객체를 공유합니다. 참조계수가 2가 됩니다.

		CreateThread(0, 0, threadMain, this, 0, 0); 
	}
	
	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// 안드로이드 참고
		//https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/Threads.cpp#L717

		// 지역변수로 스마트 포인터를 다시 생성한다.
		// 지역변수는 스코프 벗어날 때 항상 소멸자 불린다.
		std::shared_ptr<Thread> strong(self->holdme); // 이 순간 참조계수는 3 됨
		self->holdme.reset(); // 참조계수 깎여서 2가 됨
		// threadMain {} 빠져나가는 순간 지역변수 strong 파괴되면서 참조계수 깎임.
		// 이때 외부의 sp가 아직 살아있다면 레퍼런스 카운트는 1이 되는것이고, 
		// 이미 sp가 죽고 없다면 카운트는 0이 되어서 최종 파괴됨.
				
		self->threadLoop();

		// 자신의 참조계수를 가지고 있던 스마트 포인터를 RESET 합니다.
		//self->holdme.reset(); // 이걸 주석으로 막으면 절대 파괴안됨. 소멸자 안 불림.
		// 근데 이걸 사용자가 안 불러주는 위험도 있다. 위에서 exception 날수도 있으므로.
		
		return 0;
	}

	virtual void threadLoop() = 0;
};

class MyThread : public Thread
{
	int data = 0;
public:
	virtual void threadLoop()
	{
		std::cout << "MyThread" << std::endl;
		data = 10;
	}
};
int main()
{		
	{
		std::shared_ptr<MyThread> sp(new MyThread);
		sp->run();
		getchar();
	} // 이 스코프를 나가면 sp가 파괴되므로 나중에 그 안에 data 수정할 때 문제가 생긴다.
	// 계속 살아있게 만들어야 하므로 holdme 만들어줌.
		
}
