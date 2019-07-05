// 8_policy - 183 page (policy clone)

// 참고:
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
// 동기화 정책을 담은 정책 클래스를 제공합니다.
struct nolock
{
	// 아무 일도 안하는 inline 함수는 실제 호출 안되고 그냥 지워진다.
	inline void lock() {}
	inline void unlock() {}

	// 이제 무조건 아무일도 안하더라도 함수 2개는 꼭 만들어줘야 하는데
	// 이걸 강제하려면 인터페이스를 써야 하는데 가상함수는 성능저하라서 쓰기 싫고
	// 그래서 문서화해서 꼭 이 2개 함수를 만들라고 스펙을 적었는데
	// 이제는 그런 문서조차 쓰기 싫으니까
	// concept : cpp20부터 등장.

};
struct posix_mutex_lock
{
	// 필요할 때만 mutex 가지고 있는 이 정책을 불러서 사용하면 됨.
	inline void lock() {} // pthread_mutex_acquire()
	inline void unlock() {}
};
//----------------------
//List<int> s; // 전역변수. 멀티스레드에 안전하지 않다. 
List<int, nolock> s; // 그럼 내부적으로 lock을 쓰도록 하면? 멀티스레드 안쓸때는 쓸데없이 성능저하잖아.
// 그래서 policy를 선택 가능하도록 했다.


int main()
{
	s.push_front(10);
}