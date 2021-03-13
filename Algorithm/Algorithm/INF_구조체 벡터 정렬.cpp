#include<iostream> 
#include<vector>
#include<algorithm> 
using namespace std;
struct Loc { // ����ü ���� 
	int x, y, z; // ����ü ��� ���� 
	Loc(int a, int b, int c) { // ����ü ������ ����(�ʱ�ȭ�ϱ� ����) 
		x = a;
		y = b;
		z = c;
	}
	// ũ�⸦ ���ϴ� ������, ������ �����ε� ��, �� ��ü�� ũ�⸦ ����, ���ı����� ���� 
	bool operator<(const Loc& b)const { // ����ü�� �ּҷ� ����, b�� ���ؼ� ������ �ٲ�, �̸� �����ϱ� ���ؼ� const ���� 
		// operator�� const�� �����Ͽ� x,y,z�� ������ �� ���� ��
		return x < b.x; // opreator�� �־ ȣ���� ��ü x�� �տ� Loc &b�ؼ� �Ѿ�� ���ڷ� �Ѿ�� ��ü�� �ڿ� �׸��� �տ����� ������ �ڿ����� ū �ɷ� ������ �ϰԲ� ������������ ������ 
	}
};
int main() {
	// freopen("input.txt","rt",stdin);
	vector<Loc> XY; // ����ü�� vector ����
	XY.push_back(Loc(2, 3, 5));
	XY.push_back(Loc(3, 6, 7));
	XY.push_back(Loc(2, 3, 1));
	XY.push_back(Loc(5, 2, 3));
	XY.push_back(Loc(3, 1, 6)); // ����ü ������ Ȱ���Ͽ��� �� ���� ����
	sort(XY.begin(), XY.end()); // ������ ��Ŵ, x�� �������� ����ü ��ü�� ���Ľ�Ŵ, �� 2, 3, 5������ x �� 2�� ������ ������ ���� ���� ������ 
	for (auto pos : XY) cout << pos.x << " " << pos.y << " " << pos.z << endl;
	return 0;
}