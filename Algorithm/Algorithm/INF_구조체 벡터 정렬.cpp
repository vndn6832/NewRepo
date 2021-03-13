#include<iostream> 
#include<vector>
#include<algorithm> 
using namespace std;
struct Loc { // 구조체 선언 
	int x, y, z; // 구조체 멤버 선언 
	Loc(int a, int b, int c) { // 구조체 생성자 선언(초기화하기 위햬) 
		x = a;
		y = b;
		z = c;
	}
	// 크기를 비교하는 연산자, 연산자 오버로딩 함, 두 객체의 크기를 비교함, 정렬기준을 잡음 
	bool operator<(const Loc& b)const { // 구조체를 주소로 받음, b를 통해서 원본을 바꿈, 이를 차단하기 위해서 const 선언 
		// operator를 const로 선언하여 x,y,z를 변경할 수 없게 함
		return x < b.x; // opreator에 있어서 호출한 객체 x는 앞에 Loc &b해서 넘어온 인자로 넘어온 객체는 뒤에 그리고 앞에것을 작은것 뒤에것을 큰 걸로 정렬을 하게끔 오름차순으로 정렬함 
	}
};
int main() {
	// freopen("input.txt","rt",stdin);
	vector<Loc> XY; // 구조체형 vector 선언
	XY.push_back(Loc(2, 3, 5));
	XY.push_back(Loc(3, 6, 7));
	XY.push_back(Loc(2, 3, 1));
	XY.push_back(Loc(5, 2, 3));
	XY.push_back(Loc(3, 1, 6)); // 구조체 생성자 활용하여서 그 값을 넣음
	sort(XY.begin(), XY.end()); // 정렬을 시킴, x를 기준으로 구조체 객체를 정렬시킴, 즉 2, 3, 5에서의 x 값 2의 값으로 정렬함 뒤의 값은 무관함 
	for (auto pos : XY) cout << pos.x << " " << pos.y << " " << pos.z << endl;
	return 0;
}