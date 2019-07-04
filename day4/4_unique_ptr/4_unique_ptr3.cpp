//4_unique_ptr3
#include <iostream>
#include <memory>

// ������ �Լ� ��ü
template<typename T> struct default_delete
{
	inline void operator()(T* p) // ����� void �����ͷ� ������! �Ҹ��� �θ����� ��Ȯ�� Ÿ���� �˾ƾ���.
	{
		std::cout << "default delete" << std::endl;
		delete p;
	}
};

struct Freer
{
	// free�� �Ҹ��ڸ� ȣ������ �����Ƿ� void* �� ����ص� �˴ϴ�.
	inline void operator()(void* p)
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

template<typename T, typename D = default_delete<T> >
class unique_ptr
{
	T* obj;
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	inline ~unique_ptr() { 
		D d;
		d(obj); // ������ �Լ� ��ü�� ����ؼ� ����.
	}
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

};
int main()
{
	unique_ptr<int>  p1(new int);
	unique_ptr<int, Freer> p2((int*)malloc(100));
	// ����ũptr: ������ �ٸ��� ���ٰ� �ؼ� �ٸ� Ÿ���� �Ǿ����. �ٵ� ������ ����.


	//*********************

	//std::unique_ptr<,,
	// �Ʒ� sp1, sp2�� �ٸ�Ÿ��? ����Ÿ��?
	//std::shared_ptr<int> sp1(new int);
	//std::shared_ptr<int> sp2(new int, foo);
	// ���� Ÿ��. Ÿ�� ������. ���� �����̳ʿ� �� ����. 
	// shared ptr: ������ ����.
}
