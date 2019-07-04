//3 �Լ���ü4
#include <iostream>

template<typename T> void foo(T f)
{
	std::cout << __FUNCSIG__ << std::endl;
	f(1, 2);
}
int main()
{
	// cpp11 ����ǥ���� : 
	foo([](int a, int b) {return a + b; });
	// �����Ϸ��� � class�� ����°Ŵ�. �׸��� �� Ŭ������ ���ؼ� �ӽð�ü�� ����� ������.
	// class xx{int operator()(int, int)}; xx();

	[](int a, int b) { return a + b; }(1, 2); // ����ǥ�����̸����ӽð�ü(1,2);

	auto f = [](int a, int b) { return a + b; };	
	f(1, 2);

	// **********************************************
	// ����!!!
//	auto& a1 = [](int a, int b) { return a + b; };			// 1: rvalue�� �ӽð�ü�� ������ ���� �� ����.
	const auto& a2 = [](int a, int b) { return a + b; };	// 2: ok. const ������ �� ���� �� �ִ�.
	auto&& a3 = [](int a, int b) { return a + b; };			// 3: ok.

	// ù�� ���蹮��
	// f�� ���ٸ� ��Ÿ���� �ӽð�ü xx Ÿ���̶�� �� ��,
	/*
	decltype(f) f2; // ??? �̰� ����.	
	// f�� �Ȱ��� Ÿ���� ���� f2�� ���������? 
	// �ȵȴ�. ����ǥ������ ����� Ŭ��������
	// ����Ʈ �����ڸ� ����� �� �����ϴ�.

	ClosureType::ClosureType()
	ClosureType() = delete;  (until C++14)
	ClosureType() = default; (since C++20)(only if no captures are specified)

	�̰� cpp20���ʹ� �� ����������.

	*/

	decltype(f) f3(f); // ok. 
	// ����Ʈ �����ڴ� ������ ���� �����ڴ� ����.
	// void foo(T f) // T f = ����ǥ����() �̷��� �޾ƾ� �ϹǷ� ��������ڴ� �ʿ���.

	int n = 10;
	//int&& r   = 10; // rvalue reference�̴�. ������Ÿ�� Ȯ��.
	// T&& r    = �Լ�����; �̰Ŵ� T�� ���۷����� �Ȱ� ���� �� �����Ƿ� ���ڿ� ���� �޶���; forwarding reference
	// auto&& r = �캯; �̰ŵ� �캯�� ���Ŀ� ���� �޶����� forwarding reference �̴�. auto�� �׻� T�� ����. �������� ��.
	auto&& a5 = 10; // int&& a5 = 10
	auto&& a6 = n;  // int& a6 = n

}
