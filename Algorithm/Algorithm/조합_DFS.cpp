#include<iostream>
using namespace std;
int n, r; //n: ������ ��, r: �����ؾ��ϴ� ���� ����
int cnt = 0; //���� ��
int ch[20];
void DFS(int s, int l) { // ���� ����(start)�� l(level)�� �Ű������� �޴´�

	if (l == r) { // ����Լ� ��������: l==r (��, �������� ���ڸ� ��� �̾��� ��)
		for (int i = 0; i < r; i++) {
			cout << ch[i] << " "; 
		}//����Լ��� ����Ǳ� �� ���� ���ڵ��� �����ְ�,

		cout << endl;
		cnt++; //������ ������ ���ϱ� ���� ++
	}
	else {
		for (int i = s; i < n; i++) {
			ch[l] = i;
			DFS(i + 1, l + 1); // DFS() �Լ��� ����� ����+1, level+1�� ���ڷ� �Ѱ��ش�
		}
	}

}
int main() {
	cin >> n >> r;

	DFS(0, 0);

	cout << cnt << endl;
}