// page 73
#include <iostream>
using namespace std;

// new�� ����ϸ� operator new() �� ȣ��˴ϴ�.
void* operator new(size_t sz)
{
	void* p = malloc(sz);
	if (p == nullptr)
		throw std::bad_alloc();
	return p;
}

// �Լ� �����ε��� empty�� ����ϴ� ��찡 ���� �ֽ��ϴ�.
struct __nothrow_t {};
//__nothrow_t nothrow;

void* operator new(size_t sz, __nothrow_t)
{
	void* p = malloc(sz);

	return p;
}

int main()
{
	try
	{
		int* p1 = new int; // �޸� ������ std::bad_alloc ���� �߻�
	}
	catch (std::bad_alloc& b) {}
	
	int* p2 = new(nothrow) int; // �޸� ������ 0 ��ȯ 
	if (p2 == nullptr) {}


}