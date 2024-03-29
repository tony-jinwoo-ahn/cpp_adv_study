// 143 page 멤버 디텍터

#include <iostream>
#include <type_traits>

class Shape
{
public:
//	virtual void Draw() = 0;
};

// 핵심 1. 함수 템플릿 버전과 가변인자 버전의 2개의 함수를 만든다.
//		2. template 버전은 조건을 만족하지 않으면 실패하게 만든다.

// T arg: 추상클래스라면 실패. 하지만 인자를 보낼 때 객체가 필요!
// T* arg: 추상클래스라도 포인터는 만들 수 있다.
// T(*arr)[1] : 배열을 가리키는 포인터 - 추상클래스는 배열을 
//				가리키는 포인터를 만들 수 없다.

// 추상이 아니면 위에꺼 쓴다. 추상이면 치환 실패.
template<typename T> int Test(T(*arr)[2]); // T타입의 2개짜리 배열을 가리키는 포인터. 
//크기는 의미가 없다. 1 줘도 되고 2 줘도 되고. 
//여기서 그냥 T를 하면 객체를 전달해야 하는데, 추상은 객체를 못 만드니까 안된다.
// 배열을 가리키는 포인터는 클래스의 크기를 알아야 하는데 
// 추상은 실체 크기가 없으니까 안되는 것을 이용해서 치환 실패하도록 유도하는 테크닉.

// 추상이면 위에꺼는 실패하고 밑에 가변인자꺼 쓴다.
template<typename T> char Test(...); // 구현부는 빼자. 실행할거 아니다. 컴파일타임에 조사만 하는 용도.

int main()
{
//	Shape s; 추상클래스는 객체 생성 못함
//	Test<Shape>(s);

	// 객체는 못 만들어도 포인터 주소값 0은 넘길 수 있다.
	//Test<Shape>(0); // 호출. 평가되는 표현식

	// 호출하지말고, 어느 함수가 호출되는지만 조사.
	int n = sizeof( Test<Shape>(0) );

	std::cout << n << std::endl;
}
