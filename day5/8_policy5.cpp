#include <iostream>
#include <vector>

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << __FUNCSIG__ << std::endl; }
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};

template <class T>
struct Mallocator {
	typedef T value_type;
	Mallocator() = default;
	template <class U> constexpr Mallocator(const Mallocator<U>&) noexcept {}
	T* allocate(std::size_t n) {
		if (n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
		if (auto p = static_cast<T*>(std::malloc(n * sizeof(T)))) return p;
		throw std::bad_alloc();
	}
	void deallocate(T* p, std::size_t) noexcept { std::free(p); }

	void destroy(T* p)
	{
		std::cout << "Mallocator destroy" << std::endl;
		p->~T();
	}

};
template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) { return false; }

// 아래 코드가 Policy Clone 이름을 가진 기법
template<typename U>
struct rebind
{
	typedef Mallocator<U> other;
};


// List를 생각해 봅시다.
template<typename T, typename Ax = std::allocator<T>>
class List
{
	struct Node
	{
		T data;
		Node *next, *prev;
	};
	// Ax ax; // Mallocator<int> ax;
			// int 가 아닌 Node 의 할당기가 있어야 한다.
	//Mallocator<int>::rebind<Node>::other ax;
						// Mallocator<Node> 가 되었다
	typename Ax::template rebind<Node>::other ax;
						// Mallocator<Node>


public:
	void push_front(const T& a)
	{
		// 메모리 할당이 필요함. 어떻게 해야 할까?
	}
};

int main()
{
	List<int, Mallocator<int>> s;
	s.push_front(10);
}
