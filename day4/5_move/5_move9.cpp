

#include <iostream>
#include <string>
#include <vector>


class Test
{
	int data;
	std::string s = "hello";
public:
	Test() {}
	~Test() {}
	Test(const Test& t) : data(std::move(t.data)), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
	Test& operator=(const Test& t) {
		data = t.data;
		s = std::move(t.s);

		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}



	Test(Test&& t) noexcept (
		std::is_nothrow_move_constructible<std::string>::value)
		: data(t.data), s(std::move(t.s))
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	Test& operator=(Test&& t) noexcept (
		std::is_move_assignable<std::string>::value)
	{
		data = t.data;
		s = std::move(t.s);
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};


template<typename T> void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);

}

// 1. ����ڰ� ����� move�� ��� �������� ������
// => �����Ϸ��� ��� ������ �ش�.
// 
// 2. ����ڰ� ���� �迭�Լ��� �����ϸ�
//    �����Ϸ��� move �迭�� �������� �ʴ´�.
// ���: �ƹ��͵� ������ ������
// rule of 0 : ����ڰ� ���� �ڿ��� �������� ������
//             �Ҹ���, ����迭 2��, move�迭 2���� ���� �ʿ� ����.
//             �����Ϸ��� ��� ����! ���� ��ڴ�!
class Object
{
	Test data;
	//char* s; // �̰� ������ ��������� ��¿������ �������� ��. ���� raw pointer ��������.
	//std::string s; // �̰� ���! string �̵� vector�� ���� �ȴ�.
	// �Ժη� ������ raw�ϰ� ������ �̰����� �Ϻ��ϰ� �� �˾Ƽ� �������� �Ѵ�. �����Ϸ��� �˾Ƽ� �ϰ� �ض�.

public:
	Object() {}
	Object(const Object& o) : data(o.data) {}
};

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o2);
}
