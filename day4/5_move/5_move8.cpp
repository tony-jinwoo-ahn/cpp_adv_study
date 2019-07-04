

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

// move�� �˰���
// move���� �˾ƾ� �ϴ� ��
// 1. Ŭ���� ���� �� move �迭 �Լ� 2���� ����� ��
// 2. �Ϲ� �˰��� ������ �� move() �� ����ؼ� 
//    �ű�� ���� ���� ��찡 �ִ�.

template<typename T> void Swap(T& a, T& b)
{
	/*
	�߸� ���� �����̴�. ���縦 ���� �ִ�.
	T tmp = a;
	a = b;
	b = tmp;
	*/

	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);

}

int main()
{
	Test t1, t2;
	Swap(t1, t2);
}
