#include <iostream>
 
using namespace std;
 
int main() {
    int a[100][100];
    int n, m; 
    int reverse = 1;
    cin >> n >> m;
    //int row = -1, col = m - 1;
    int col = 0, row = -1;
    int limit = 0;
    //총반복의 횟수는 n*m의 숫자까지
    for (int count = 1; count <= m * n;) {
        //가로 채우기
        for (int i = 0; i < m - limit; i++) {
            row += reverse;
            a[col][row] = count++;
        }

        //세로 채우기
        for (int i = 0; i < n - limit - 1; i++) {
            col += reverse;
            a[col][row] = count++;
        }

        //반복이 한번될때마다 역전시킨다.
        reverse = -reverse;
        //최대 반복횟수 감소
        limit++;
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}