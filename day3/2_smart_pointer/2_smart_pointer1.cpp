#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<int> sp1(new int);
	std::shared_ptr<int> sp2 = sp1;

	// smart pointer의 크기는 일반적으로 raw pointer의 2배이다.(그래서 4*2 = 8바이트 차지)
	std::cout << sizeof(sp1) << std::endl;
	std::cout << sp1.use_count() << std::endl;	

	//----------------------------
	// 아래 코드는 절대 안됩니다.
	// 자원을 관리하기 위한 관리 객체가 sp3, sp4 각각 생성됩니다. 
	int* p = new int;
	std::shared_ptr<int> sp3(p);
	std::shared_ptr<int> sp4(p);

	std::cout << sp3.use_count() << std::endl;
	std::cout << sp4.use_count() << std::endl;
	getchar();

	// RAII: Resource Acquisition Is Initialization
	// 자원을 할당하는 것은 자원 관리 객체가 초기화될때 이어야 한다.
	std::shared_ptr<int> sp5(new int); // OK!
	// 질문: 첫날 수업한 생성자와 메모리할당을 분리하는거에 스마트 포인터를 적용 가능할까?

}
