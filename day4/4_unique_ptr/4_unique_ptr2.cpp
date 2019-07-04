//4_unique_ptr2
#include <iostream>

template<typename T>
class unique_ptr
{
	T* obj;
public:
	inline unique_ptr(T* p = 0) : obj(p) {}
	inline ~unique_ptr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	// 복사생성자와 대입연산자를 삭제
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

};
int main()
{
	unique_ptr<int> p1(new int);	
	*p1 = 10;
//	unique_ptr<int> p2 = p1; // 얕은 복사 일어나서 이중 delete 나서 죽음.
	// 해결책: 관리객체를 만들거나, 복사생성자를 지워서 아예 이렇게 못 쓰게 막거나.
}
