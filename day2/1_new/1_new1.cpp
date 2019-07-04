// android source github
// platform system core/ libutils/include/utils/
/*

template<typename TYPE>
typename std::enable_if<traits<TYPE>::has_trivial_copy>::type
inline
copy_type(TYPE* d, const TYPE* s, size_t n) {
	memcpy(d,s,n*sizeof(TYPE));
}

*/

// p. 103 Generic Container Idioms

#include <iostream>
using namespace std;

// 핵심1. new의 2가지 사용법
// new Point(1,1): 메모리할당 후 생성자 호출
// new(p) Point(1,1): 이미 존재하는 메모리(주소 p)에 생성자 호출
//					placement new (위치 지정 new)

// 핵심2. 생성자 호출없이 메모리만 할당하는 기법
// operator new( 메모리크기 )

// 핵심3
// delete p1; 소멸자 호출, 메모리 해지
// operator delete(p1); 메모리만 해지

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}
	~Point()
	{
		cout << "Dtor~" << endl;
	}
};
int main()
{
	// malloc: 메모리만 할당
	// new : 메모리할당 + 생성자 호출 (cpp 진영에선 이둘을 동시에 부르는걸 불편해함. 분리호출 가능!)
	//Point* p1 = new Point(0, 0);
	//delete p1; 소멸자 호출후 메모리 해지

	//1. only alloc mem
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));
	cout << "alloced addr: " << p2 << endl;

	// 2. ctor to alloced mem
	new(p2) Point(0, 0);

	// 메모리 할당과 생성자 호출을 분리한 경우
	// 소멸자 호출과 메모리 해지도 분리한다.
	// 3. 소멸자 호출
	p2->~Point(); 

	// 4. 메모리만 해지.
	operator delete(p2); 

}
