// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h"
using namespace cppmaster;


class Window
{
	int hwnd;
public:
	void Create()
	{
		hwnd = ec_make_window(&handler);		
	}
	// 핵심 1. 아래 함수는 반드시 static 멤버 함수가 되어야 합니다. 
	//(파라미터에 this 가 넘어오지 못하게.)
	//Window* this 가 추가되면 인자가 5개가 되어버리니까.
	static int handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "L BUTTON" << std::endl; break;
		case WM_KEYDOWN: std::cout << "KEY DOWN" << std::endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.Create();
	ec_process_message();	
}
