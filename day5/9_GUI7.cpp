// 9_GUI
#define USING_GUI
#include <iostream>
#include "cppmaster.h" // 카페(cafe.naver.com/cppmaster)에 있습니다.
using namespace cppmaster;
#include <map>

class Window
{
protected:
	int hwnd;
	static std::map<int, Window*> this_map;
public:
	void LButtonDown() {}
	void KeyDown() {}

	// Factory Method
	// 아래 함수에서 DoCreate()가 Factory Method 입니다.
	void Create() { DoCreate(); }
	virtual void DoCreate() = 0;
};
std::map<int, Window*> Window::this_map;

// CRTP로 메세지를 처리하기 위한 파생 클래스
// WTL 
template<typename T> class MsgWindow : public Window
{
public:
	virtual void DoCreate() override
	{
		hwnd = ec_make_window(&handler);
		this_map[hwnd] = this;
	}
	static int handler(int handle, int msg, int a, int b)
	{
		T* self = static_cast<T*>(this_map[handle]);
		switch (msg)
		{
		case WM_LBUTTONDOWN:	self->LButtonDown();	break;
		case WM_KEYDOWN:		self->KeyDown();		break;
		}
		return 0;
	}
};
//--------------------------------------------
class MyWindow : public MsgWindow<MyWindow>
{
public:
	void LButtonDown() { std::cout << "MyWindow LButtonDown" << std::endl; }
};

int main()
{
//	MyWindow w;
//	w.Create();

	Window* p = new MyWindow;
	p->Create(); // ???

	ec_process_message();
}

// C++ nana library 참고
// 2017에 등장한 최신 cpp 기술 적용된 GUI 라이브러리
