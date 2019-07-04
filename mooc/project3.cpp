// prj3 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>

using namespace std;

struct People
{
	string name;
	int age;
	People(string n, int a) : name(n), age(a) {}
	void Dump() const { cout << name << "(" << age << ")" << endl; }
};


int main()
{
	vector<shared_ptr<People>> v;
	auto item = std::make_shared<People>("kim", 10);	
	v.push_back(item);

	item = std::make_shared<People>("lee", 15);
	v.push_back(item);

	item = std::make_shared<People>("park", 5);
	v.push_back(item);

	item = std::make_shared<People>("jung", 20);
	v.push_back(item);

	item = std::make_shared<People>("choi", 12);
	v.push_back(item);
		
	cout << "이름순으로 정렬해서 출력해 보세요" << endl;
	std::stable_sort(v.begin(), v.end(), 
		[](shared_ptr<People> a, shared_ptr<People> b) -> bool { return (a->name) < (b->name); });
	for (auto& x : v) {
		x->Dump();
	}

	cout << endl;

	cout << "나이순으로 정렬해서 출력해 보세요" << endl;	
	std::stable_sort(v.begin(), v.end(), 
		[](shared_ptr<People> a, shared_ptr<People> b) -> bool { return (a->age) < (b->age); });
	for (auto& x : v) {
		x->Dump();
	}

	return 0;
}
