// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h"
using namespace cppmaster;

int handler(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "L BUTTON" << std::endl;break;
	case WM_KEYDOWN: std::cout << "KEY DOWN" << std::endl;break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(&handler);
	int h2 = ec_make_window(&handler);
	ec_process_message();
}
