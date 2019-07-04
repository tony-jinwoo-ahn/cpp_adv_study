// lvalue, rvalue ��� ���޹޴� �Լ� �����!

#include <iostream>

// �Լ� ���ڷ�
// int&  : int�� lvalue�� ���� ����.
// int&& : int�� rvalue�� ���� ����.
// T&    : ��� Ÿ���� lvalue�� ���� ����.

// T&&   : ��� Ÿ���� lvalue�� rvalue ���� ����.

// lvalue(n) �� ������ T : int& �̰�, �Լ� ���������� (int&) �̴�.
// rvalue(0) �� ������ T : int  �̰�, �Լ� ���������� (int&&)�̴�.

//***************************************************

// lvalue, rvalue ��� ���޹޴� �Լ� �����!
// 1. �� ���� value 
// lvalue, rvalue �� ������, ������ �ƴ� ���纻. ��ġ�� Ŀ���� ������
void f1(int  a) {}

// 2. const lvalue reference
// �Ϲ� ������ lvalue�� ���� �� �����Ƿ�, const ���δ�.
void f2(const int& a) {} // const ������ ���� �ٲ� �� ���� ����.

// 3. 2���� �Լ�
void f3(int&  a) {}
void f3(int&& a) {} // �ϴ����� ����� �Լ��� �Ź� 2�� ������ �ϴ� ����.

// 4. 2���� �Լ��� �ڵ�����
// T&&   : forwarding reference (=universal reference) => ���������� �Ȱ� ���� �� �ִ�.
// int&& : rvalue reference (��Ȯ�� ������ Ÿ���� ������. ���̻� ���������� ���Ȱ� ���� ������ ����.)
template<typename T> 
void f4 (T&& a) {
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 0;
	f4(n); // T: ?  f1(?) ��� �������� �ܿ��� �Ѵ�. �ϱ�����! �����Ϸ��� ��� �����ϴ�����.
	f4(10);

	/*
	f4<int>(0); //  T : int   �̰�  T&& : int&&  �̴ϱ�     f4(int&&)
	f4<int&>(n); // T : int&  �̰�  T&& : int& && �̴ϱ�    f4(int&)
	f4<int&&>(0);// T : int&& �̰�  T&& : int&& &&  �̴ϱ�  f4(int&&)
	*/
}

// forwarding reference �� ���ڸ� literal�� �ް� �ƴѰŵ� �ް� �� �ްڴٴ°Ŵ�.
// �̰� ������ ������ const ���������� �����.
