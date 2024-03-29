#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
	std::vector<int> v = { 1,2,3 };
	auto p1 = v.begin();
	++p1;
	--p1;
	p1 = p1 + 3;

	std::list<int> ls = { 1,2,3 };
	auto p2 = ls.begin();
	++p2;
	--p2;
	// stl은 성능향상이 없는곳에서는 덧셈을 제공하지 않는다
	// 괜히 덧셈 제공하면 사람들이 성능이 더 좋은걸로 오해하니깐
	// 결국 ++ 을 3번 해야 하는건 똑같아
	// p2 = p2 + 3; 에러

	std::forward_list<int> fs = { 1,2,3 }; // 싱글리스트
	auto p3 = fs.begin();
	++p3;
	// --p3; // 자료구조의 특성상 뒤로 못간다
	// p3 = p3 + 3; // 에러


	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = std::find(s.begin(), s.end(), 5);
	// find 알고리즘의 1,2번째 인자는 반복자입니다.
	// 최소 요구조건은 무엇일까요?
	// 5가지 종류중에서 골라보세요.
	// 최소로 <입력반복자>만 보장하면 됨
	// 출력 필요없고, 멀티패스 필요없음.

	std::reverse(s.begin(), s.end()); // 최소 조건?
	// => 양방향 반복자 필요.
	// 여기서 싱글리스트를 쓰면 에러나겠지. -- 연산이 안되므로.

	//std::sort(s.begin(), s.end()); // 퀵소트 입니다.
	// 반을 잘라야 해. 그러려면 뺄셈이 필요함.
	// => 임의접근 반복자가 전달되어야 함.
	// 내부적으로 빼기가 되어야 하는데 list는 그게 안되므로 에러남.
	s.sort(); // 그래서 퀵소트 말고 다른 알고리즘을 쓰는 멤버함수가 제공됨.

	//질문!
	std::vector<int> vv = { 1,2,3 };
	//vv.sort(); // 이 멤버함수가 있을까요?
	// 없다... 일반함수(알고리즘) sort를 사용하면 된다.

	//std::sort()
	//https://en.cppreference.com/w/cpp/algorithm/find
	// find의 경우
	// InputIt: input iterator

}
// 입력 (컨테이너에서 꺼내오는 것)
// 출력 (컨테이너에 넣는것)

//반복자 카테고리 5가지
// 입력반복자: 입력, ++
// 출력반복자: 출력, ++
// 전진형 반복자: 입력, ++, 멀티패스 보장,     싱글리스트 반복자
// 양방향 반복자: 입력, ++, --, 멀티패스 보장, 더블리스트 반복자
// 임의접근 반복자: 입력, ++, --, +, -, [], 멀티패스 보장 => 연속된 메모리와 유사 (vector)

// deque 같은거는 연속된 메모리로 쭉 쓰다가 메모리 부족하면
// 또 다른 연속된 메모리 할당해서 링크드리스트 처럼 붙여서 쓰므로
// 덧셈 연산 가능

// 입력 버퍼는 먼저 도착한 포인터가 꺼내가면 멀티패스를 보장 못함
// find는 멀티패스 보장 안해도 됨. 주어진 구간을 한번만 가보면 됨
// sort는 반드시 멀티패스 보장하는 반복자만 보낼 수 있다. 반복자가 가볼때마다 결과가 달라지면 안되니까.
