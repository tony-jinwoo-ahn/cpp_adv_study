#include <iostream>

template <typename T> void foo(const T* a)
{
	std::cout << __FUNCSIG__ << std::endl;
}
template <typename T> void goo(const T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 0;
	foo(&n); // a가 가리키는 것은 const
	foo<int*>( (int**)&n );
	
	goo(n); // goo(const int&) 입니다
	goo<int&>(n); // goo( int& const& ) 입니다.
					// 모든 참조는 const 입니다. 따라서 const가 저절로 지워짐.
					// goo(int& &) 입니다. 이제 참조충돌에 의해서
					// goo(int&) 가 됩니다.
	int n1 = 100;
	int& r = n; // r은 죽을때까지 n만 가리키게 됩니다.
				// 즉, 변경할 수 없습니다.
				// int& const r = n; 의 의미입니다.
	r = n1; // r을 변경? r이 가리키는 곳을 변경?
	std::cout << r << std::endl;
	std::cout << n << std::endl;
	
	
}
