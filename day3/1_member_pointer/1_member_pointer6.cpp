#include <iostream>

// 일반함수 포인터
// 멤버함수 포인터
// poco

class Button
{
	//void(*handler)();
	void(Dialog::*handler)();
	Dialog* target;

public:
	void Click()
	{
		// 클릭된 사실을 외부에 알리려고 함.
		handler();
	}
};

int main()
{
	Button btn;
	btn.Click(); // 사용자가 버튼을 누르면 이 함수가 호출된다고 
				// 가정해봅시다.

}
