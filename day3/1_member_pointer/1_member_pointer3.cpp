#include <iostream>
#include <Windows.h>
#include <memory>

// std::enable_shared_from_this : this �����ͷ�
//			�ܺο��� ���� ������ü�� ������ �� �ְ� �ϴ� ��� Ŭ����
class Thread : public std::enable_shared_from_this<Thread> // CRTP ����̴�. ��ﳪ��?
{
	std::shared_ptr<Thread> holdme;
public:
	~Thread() { std::cout << "~Thread" << std::endl; }

	// �Ʒ� �ڵ�� 2���� ������ �ֽ��ϴ�. 
	// 1. raw pointer(this)�� ������ �ʱ�ȭ�ϸ�
	//		������ü�� ���� ��������� ������.
	// 2. �����ڿ��� �ʱ�ȭ�ϸ� ������ü�� ���� ����� ��
	//		��������� ��� 2�� �˴ϴ�.
	// 3. �����ڰ� ȣ��� �������� ���� �ܺ��� sp ����Ʈ �����Ͱ�
	//		�ʱ�ȭ���� ���� �����Դϴ�. ��, ������ü�� �����ϴ�.

	//Thread() : holdme(this)

	// shared_from_this() : �ܺο� ������� �ִ� shared_ptr ��
	//						���� ��ü�� ���� ����ϰ� �ϴ� �Լ�. ��ġ ��������..
	Thread() // : holdme( shared_from_this() )
	{
		// �̰� ȣ��� �������� ���� sp �� �ȸ������ �ִ� �����̴�.
	}

	void run() { 
		// ���⼭ �ʱ�ȭ�ϴ°� �ٶ���.
		holdme = shared_from_this(); // �� ���� �ܺ��� sp�� ������ü�� �����մϴ�. ��������� 2�� �˴ϴ�.

		CreateThread(0, 0, threadMain, this, 0, 0); 
	}
	
	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// �ȵ���̵� ����
		//https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/Threads.cpp#L717

		// ���������� ����Ʈ �����͸� �ٽ� �����Ѵ�.
		// ���������� ������ ��� �� �׻� �Ҹ��� �Ҹ���.
		std::shared_ptr<Thread> strong(self->holdme); // �� ���� ��������� 3 ��
		self->holdme.reset(); // ������� �𿩼� 2�� ��
		// threadMain {} ���������� ���� �������� strong �ı��Ǹ鼭 ������� ����.
		// �̶� �ܺ��� sp�� ���� ����ִٸ� ���۷��� ī��Ʈ�� 1�� �Ǵ°��̰�, 
		// �̹� sp�� �װ� ���ٸ� ī��Ʈ�� 0�� �Ǿ ���� �ı���.
				
		self->threadLoop();

		// �ڽ��� ��������� ������ �ִ� ����Ʈ �����͸� RESET �մϴ�.
		//self->holdme.reset(); // �̰� �ּ����� ������ ���� �ı��ȵ�. �Ҹ��� �� �Ҹ�.
		// �ٵ� �̰� ����ڰ� �� �ҷ��ִ� ���赵 �ִ�. ������ exception ������ �����Ƿ�.
		
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
	} // �� �������� ������ sp�� �ı��ǹǷ� ���߿� �� �ȿ� data ������ �� ������ �����.
	// ��� ����ְ� ������ �ϹǷ� holdme �������.
		
}
