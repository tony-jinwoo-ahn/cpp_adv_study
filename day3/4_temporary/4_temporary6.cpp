#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 복사생성자 모양 1. call by value
	// Point(Point p) {} // Point p = p1 이 불려야 하고 그래서 또 복사생성자가 불려야 하고... 
	// 복사생성자 무한 호출 에러.

	// 2. 참조 사용
	// rvalue를 받을수없다. 즉, 값을 반환하는 함수의 반환값을 받을수 없다.
//	Point(Point& p) {} // Point& p = p1 // 객체를 만드는게 아니므로 다시 함수를 부르지 않음. 합법적인 표현.

	// 3. const lvalue reference
	//		lvalue와 rvalue를 모두 받을 수 있다.
	//      const lvalue, const rvalue도 모두 받을 수 있다! 
	Point(const Point& p) { // 여기서 const 빼도 되나? 안된다. 그러면 const 인자로 넘어오는 애를 못받는다.
		cout << "lvalue일 때. 복사생성자" << endl;
	}	

	Point(Point&& p) { // R-value 받을수있음. 우선순위상 일단 얘부터 부른다.
		// 그러면 여기에 const로 넘어오는 애는 어떻게 하나? 못 받는다.
		// const로 되어있으면 주소를 바꿔서 자원뺏기가 불가. 

		// 임시객체의 자원을 뺏어오자. 어차피 너 파괴될거잖아.
		cout << "R-value일 때. Move 생성자" << endl;
	}
	
};

Point goo() // 참조리턴은 하면안된다. 지역변수는 반드시 파괴되므로. 임시객체 반환할 수밖에 없다.
{
	Point pt;
	return pt; // 임시객체 반환
}

int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p1); // Point(Point) 가 필요하다. 없으면 컴파일러가 복사생성자 만들어줌.

	Point p4 = goo(); // Point p4 ( goo() ); 랑 같은 모양. rvalue를 받을 수 없다.
}

