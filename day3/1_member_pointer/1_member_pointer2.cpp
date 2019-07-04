#include <iostream>
#include <Windows.h>

/*
// C ��� ��Ÿ��
DWORD __stdcall foo(void* p) // void �����͸� �ݵ�� �޾ƾ� ��
{
	return 0;
}
*/

// ������ ������ ���� Ŭ����
// �Ʒ� �ڵ带 ���̺귯�� ���� Ŭ������� �����ϼ���
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }
	/*
	DWORD __stdcall threadMain(void* p) // �� �ȿ� this�� �ֱ� ������ ����! void*�� �־�� �Ѵ�. 
		//�׷��� ����Լ��� �ȵȴ�. 
		//�ٽ�: �� �Լ��� �ݵ�� static�� �Ǿ�� �Ѵ�. 
		//�׷��� �Ķ���Ϳ� �Ͻ������� ���� this �� �����Ѵ�.
	{
		threadLoop();
		return 0;
	}
	*/
	/*
	static DWORD __stdcall threadMain(void* p) // �� �ȿ��� this�� ������, ������ �Ķ���ͷ� this�� �Ѱ��༭ �޴´�.
	{
		threadLoop(); // �̹��� �̰� ��������. static�� �ǰ��ϱ� ���������, ����Լ� ���Ұ�������.
		return 0;
	}
	*/

	// �ȵ���̵�ҽ�/platform_system_core/libutils/include/utils/Thread.h ����!
	//https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/Thread.h
	//platform_system_core/libutils/Threads.cpp ����
	//https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/Threads.cpp
	//https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/Threads.cpp#L713

	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// self�� �ᱹ this �Դϴ�.
		// self�� ����ϸ� static ����Լ������� �ٸ������ ���� ����.
		self->threadLoop();
		//threadLoop();
		return 0;
	}

	virtual void threadLoop() = 0;
};
// �Ʒ� Ŭ������ ����� Ŭ�����Դϴ�
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
	mt.run(); // �� ���� ���ο� �����尡 �����Ǿ threadLoop() �� 
				// �����ؾ� �մϴ�.
	getchar();

}