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
public:
	inline unique_ptr(T* p = 0, const D& del = D())
		: m(del, p) {}

	inline ~unique_ptr() {		
		m.getValue1()( m.getValue2() );
	}
	inline T* operator->() { return m.getValue2(); }
	inline T& operator*() { return *(m.getValue2()); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

};
int main()
{
	unique_ptr<int> p1(new int);
	unique_ptr<int, Freer> p2( (int*)malloc(100) );

	std::cout << sizeof(p2) << std::endl;
}
