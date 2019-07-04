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

	// ��������ڿ� ���Կ����ڸ� ����
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

};
int main()
{
	unique_ptr<int> p1(new int);	
	*p1 = 10;
//	unique_ptr<int> p2 = p1; // ���� ���� �Ͼ�� ���� delete ���� ����.
	// �ذ�å: ������ü�� ����ų�, ��������ڸ� ������ �ƿ� �̷��� �� ���� ���ų�.
}
