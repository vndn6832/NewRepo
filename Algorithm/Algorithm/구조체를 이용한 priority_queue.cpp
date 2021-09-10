#include <queue>
#include <iostream>
using namespace std;

struct man {
	int age;
	int h, w;
};

struct compare {
	bool operator()(const man& m1, const man& m2) {
		return m1.age < m2.age;
	}
};

priority_queue<man, vector<man>, compare> mq;

int main()
{
	man tmp;
	tmp.age = 40;
	mq.push(tmp);

	tmp.age = 50;
	mq.push(tmp);

	tmp.age = 30;
	mq.push(tmp);

	tmp.age = 1;
	mq.push(tmp);

	while (!mq.empty()) {
		cout << mq.top().age << " ";
		mq.pop();
	}

	return 0;
}