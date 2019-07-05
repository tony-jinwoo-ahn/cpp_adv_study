// 8_policy - 183 page (policy clone)

// ����:
// https://github.com/WebKit/webkit/blob/master/Source/WTF/wtf/NoLock.h


#include <iostream>

template<typename T, typename ThreadModel = nolock> class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//...
		tm.unlock();
	}
};
// ����ȭ ��å�� ���� ��å Ŭ������ �����մϴ�.
struct nolock
{
	// �ƹ� �ϵ� ���ϴ� inline �Լ��� ���� ȣ�� �ȵǰ� �׳� ��������.
	inline void lock() {}
	inline void unlock() {}

	// ���� ������ �ƹ��ϵ� ���ϴ��� �Լ� 2���� �� �������� �ϴµ�
	// �̰� �����Ϸ��� �������̽��� ��� �ϴµ� �����Լ��� �������϶� ���� �Ȱ�
	// �׷��� ����ȭ�ؼ� �� �� 2�� �Լ��� ������ ������ �����µ�
	// ������ �׷� �������� ���� �����ϱ�
	// concept : cpp20���� ����.

};
struct posix_mutex_lock
{
	// �ʿ��� ���� mutex ������ �ִ� �� ��å�� �ҷ��� ����ϸ� ��.
	inline void lock() {} // pthread_mutex_acquire()
	inline void unlock() {}
};
//----------------------
//List<int> s; // ��������. ��Ƽ�����忡 �������� �ʴ�. 
List<int, nolock> s; // �׷� ���������� lock�� ������ �ϸ�? ��Ƽ������ �Ⱦ����� �������� ���������ݾ�.
// �׷��� policy�� ���� �����ϵ��� �ߴ�.


int main()
{
	s.push_front(10);
}