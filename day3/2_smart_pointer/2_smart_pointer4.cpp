#include <iostream>
#include <memory>

int main()
{
	int *rp = nullptr;// raw pointer의 문제점: 객체가 파괴된 사실을 알 수 없다.
	std::weak_ptr<int> wp; // 그래서 쓰는게 wp. 참조계수가 증가하지 않는 스마트포인터.
	
	{
		std::shared_ptr<int> sp1(new int);
		std::shared_ptr<int> sp2 = sp1; // 참조계수 증가
		
		rp = sp1.get(); // 진짜 포인터 꺼내기
		wp = sp1;

		std::cout << sp1.use_count() << std::endl;
	}
	if (wp.expired())
	{
		std::cout << "wp: 객체가 파괴됨" << std::endl;
	}
	// weak ptr까지 다 사라져야 관리객체가 비로소 제거될 수 있다.

	// shared_ptr의 관리객체는 보통 4개로 구성됨
	// strong count: 객체수명 카운트
	// weak count: 관리객체 자기 자신의 수명 카운트 (strong ptr, weak ptr 등)
	// 자원
	// 삭제자

	// make_shared 쓰면 한번에 연속된 메모리를 할당하는데, 관리객체는 제거하지 말고 좀더 냅둬야 한다.
	// 그런데 메모리 부분 해지는 불가하므로
	// 메모리 해지는 안하고 일단
	// 소멸자만 불린다.
	// 나중에 weak ptr까지 전부 사라져야 메모리 해지한다.


	// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/RefBase.h
	// weakref_impl* const mRefs;
	// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/RefBase.cpp#L148
	// class RefBase::weakref_impl : public RefBase::weakref_type


	if (rp != nullptr) 
	{
		std::cout << "객체사용" << std::endl;
	}

}
