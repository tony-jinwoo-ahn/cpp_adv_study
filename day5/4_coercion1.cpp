//4_coercion - 43 page
template <typename T> 
class Point
{
	T x, y;
public:
	Point(T a = T(), T b = T()) : x(a), y(b) {}

	// generic (복사) 생성자
//	template <typename U>
//	Point(const Point<U>& p) : x((p.x)), y((p.y)) {}

	template <typename U>
	Point(const Point<U>& p);

	template<typename> friend class Point;
};
// 클래스 템플릿의 멤버 템플릿의 외부 구현
template <typename T> // 절대로 이 뒤에 콤마 찍고 typename U 적으면 안돼. 그러면 이 Point 클래스 자체가 T,U 둘다 받는거로 오해함.
template <typename U> // 이렇게 따로 적어줘야 함. 
Point<T>::Point(const Point<U>& p) : x(p.x), y(p.y)
{
}


int main()
{
	Point<int> p1(1, 2); // 위에 있는 일반 생성자를 부름
	Point<int> p2 = p1; // 복사 생성자 사용 ok
	Point<double> p3 = p1; // ??? error
							// p3와 p1은 다른 타입이므로
							// 복사 생성자를 사용할 수 없다.
}
 