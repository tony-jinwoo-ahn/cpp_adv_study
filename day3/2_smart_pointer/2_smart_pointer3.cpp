#include <iostream>
#include <memory>

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	std::shared_ptr<int>  p1(new int); // p1의 소멸자에서 delete
	//std::shared_ptr<void> p2(malloc(100), 삭제자함수);
	//std::shared_ptr<void> p2(malloc(100), foo); 옛날 스타일
	std::shared_ptr<void> p2(malloc(100),
		[](void*p) { free(p); }); // 관리객체에 삭제자 보관 필요!
	// unique ptr은 삭제자를 보관할 곳이 없어서 재미난 기법을 사용한다!

	// 결국 관리 객체안에 삭제자를 보관하게 됩니다.
	
}
