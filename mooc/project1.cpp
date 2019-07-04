// prj1 
#include <iostream>
using namespace std;

template<typename InputIter, typename OutputIter, typename Pred>
OutputIter xcopy_if(InputIter begin, InputIter end, OutputIter target, Pred func) {
	while (begin != end) {
		if (func(*begin)) {
			*target = *begin;
			++target;
		}
		++begin;
	}
	return target;
}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int y[10] = { 0 };
	xcopy_if(x, x + 10, y, [](int a) { return a % 2 == 0; });
	for (auto n : y)
		cout << n << endl;

	return 0;
}
