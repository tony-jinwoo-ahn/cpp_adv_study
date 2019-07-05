// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h"
using namespace cppmaster;

#include <map>

// 핵심2. this를 자료구조에 보관하는 기술
class Window
{
	int hwnd;
	static std::map<int, Window*> this_map;

public:
	void Create()
	{
		hwnd = ec_make_window(&handler);

		// 윈도우 번호를 키값으로 this 보관
		this_map[hwnd] = this;
	}

	// 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 합니다. 
	//(파라미터에 this 가 넘어오지 못하게.)
	//Window* this 가 추가되면 인자가 5개가 되어버리니까.
	static int handler(int handle, int msg, int a, int b)
	{
		// 현재 윈도우 번호를 가지고 this를 얻어온다.
		Window* self = this_map[handle];

		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			self->LButtonDown();  // this->LButtonDown() 인데, 이거 static 함수라서 this 없다.
			break;
		case WM_KEYDOWN: self->KeyDown(); break;
		}
		return 0;
	}
	virtual void LButtonDown() {}
	virtual void KeyDown() {}
};
std::map<int, Window*> Window::this_map;

class MyWindow : public Window
{
public:
	virtual void LButtonDown() override
	{
		std::cout << "MyWindow LButton" << std::endl;
	}
	virtual void KeyDown() override
	{
		std::cout << "MyWindow KeyDown" << std::endl;
	}
};

int main()
{
	Window w;
	w.Create();
	ec_process_message();
}
