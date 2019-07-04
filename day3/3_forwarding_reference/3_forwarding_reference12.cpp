#include <iostream>

struct Test
{
	int data;

	void foo() &  { std::cout << __FUNCSIG__ << std::endl; }
	void foo() && { std::cout << __FUNCSIG__ << std::endl; }
	void 푸() & { std::cout << __FUNCSIG__ << std::endl; }
};

int main()
{
	Test t; // 이름이 있습니다. 블럭을 벗어날 때까지 생존.
			// 이름을 통해서 언제라도 접근가능. lvalue
	t.foo();
	t.data = 999;

	Test(); // 이름이 없습니다. 단일문장에서만 사용. rvalue 이며, 
			// 세미콜론을 만나면 즉시파괴. 임시객체.
	
	// Test().data = 10; // 임시객체에 값을 넣어봤자 바로 죽으니까 무쓸모. 그래서 rvalue 취급

	Test().foo();

	Test&& r = Test();
	r.foo();

}
