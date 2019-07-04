#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	std::list<int> v = { 1,2,3,4,5 };
	auto p = v.begin();

	// p 를 3칸 전진하고 싶습니다. 가장 좋은 코드는 뭘까요?
	//p = p + 3; // vector는 되지만 list는 안됨
	std::advance(p, 3); // 임의접근이면 +3, 임의접근아니면 ++ 을 3번 해줌.
	// 1. 앞으로 가급적 advance() 쓰자.
	// 2. 그럼 이 함수는 어떻게 만든걸까?

}
