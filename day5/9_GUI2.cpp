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
	// �ٽ� 1. �Ʒ� �Լ��� �ݵ�� static ��� �Լ��� �Ǿ�� �մϴ�. 
	//(�Ķ���Ϳ� this �� �Ѿ���� ���ϰ�.)
	//Window* this �� �߰��Ǹ� ���ڰ� 5���� �Ǿ�����ϱ�.
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
