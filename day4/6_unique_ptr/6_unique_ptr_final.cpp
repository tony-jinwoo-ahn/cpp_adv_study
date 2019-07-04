#include <iostream>
#include <memory>


template<typename T,
	typename U,
	bool b = std::is_empty<T>::value>
	struct PAIR;

template<typename T, typename U>
struct PAIR<T, U, false>
{
	T v1;
	U v2;
	T& getValue1() { return v1; }
	U& getValue2() { return v2; }

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: v1(std::forward<A>(a))
		, v2(std::forward<B>(b)) {}
	PAIR() = default;
};

template<typename T, typename U>
struct PAIR<T, U, true> : public T
{
	U v2;
	T& getValue1() { return *this; }
	U& getValue2() { return v2; }

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a))
		, v2(std::forward<B>(b)) {}
	PAIR() = default;
};


template<typename T> struct default_delete
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete p;
	}
};
template<typename T> struct default_delete<T[]>
{
	inline void operator()(T* p)
	{
		std::cout << "default delete" << std::endl;
		delete[] p;
	}
};

struct Freer
{
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

template<typename T, typename D = default_delete<T> >
class unique_ptr
{
	//	T* obj;
	//	D d;
	PAIR<D, T*> m; // empty가 앞쪽에 들어가야 동작한다!!!  

	// T가 int[]일 경우는
	// PAIR<D, int[]*>
	// 이런 모양이 되므로 에러.

public:
	inline unique_ptr(T* p = 0, const D& del = D())
		: m(del, p) {}

	inline ~unique_ptr() {
		m.getValue1()(m.getValue2());
	}
	inline T* operator->() { return m.getValue2(); }
	inline T& operator*() { return *(m.getValue2()); }

	// 복사계열은 금지
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	// move 계열은 제공
	inline unique_ptr(unique_ptr&& p) noexcept
		: m(std::move(p.m))  // PAIR move 생성자
	{
		p.m.getValue2() = nullptr;
	}

	inline unique_ptr& operator=(unique_ptr&& p) noexcept
	{
		m = std::move(p.m);
		p.m.getValue2() = nullptr;
		return *this;
	}

};
template<typename T, typename D>
class unique_ptr < T[], D >
{
	PAIR<D, T*> m; // PAIR<D, int*> m

public:
	inline unique_ptr(T* p = 0, const D& del = D())
		: m(del, p) {}

	inline ~unique_ptr() {
		m.getValue1()(m.getValue2());
	}

	// 배열 버전에서는 []를 제공하는 것이 좋습니다
	T& operator[] (int idx)
	{
		// m.getValue2() : 보관된 포인터 꺼내기.
		return m.getValue2()[idx];
	}

	inline T* operator->() { return m.getValue2(); }
	inline T& operator*() { return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

};
int main()
{
	// 이번 소스에서 변한것.
	// 1. 생성자 변경 - forwarding reference 사용
	// 2. unique_ptr 안에 move 생성자 추가.

	Freer f;	
	unique_ptr<int, Freer>   p1(new int, std::move(f));
	unique_ptr<int> p2(new int);
//	unique_ptr<int> p3 = p2; // error
	unique_ptr<int> p4 = std::move(p2); // 되야 한다.

// 아래 이거들 되게 할려면?
//	unique_ptr<Dog> p5(new Dog); // ???
//	unique_ptr<Animal> p6 = std::move(p5); // ???
// 내일 coersion 배우면 된다!
	
}
