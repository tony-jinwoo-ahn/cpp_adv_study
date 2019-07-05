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


int main()
{
	Mallocator<Point> ax;
	Point* p1 = ax.allocate(2);

//	ax.construct(&p1[0], 1, 2); // 생성자 호출
//	ax.construct(&p1[1], 1, 2);
//	ax.destroy(&p1[0]);
//	ax.destroy(&p1[1]);

	std::allocator_traits<Mallocator<Point>>::construct(
		ax, &p1[0], 1, 2);
	std::allocator_traits<Mallocator<Point>>::destroy(
		ax, &p1[0]);

	ax.deallocate(p1, 2);	
}
