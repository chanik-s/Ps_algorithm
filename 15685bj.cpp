#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define first X
#define second Y
// ���� x �� , �Ʒ� y��
//d=0 �� 1 �� 2 �� 3 ��
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

int board[105][105]; //100x 100 ��
int n;
int x, y, d, g;
int cnt;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) { //n���� ������ �巡�� Ŀ��
		cin >> x >> y >> d >> g;
		
		vector<int> v; //���� ����
		v.push_back(d % 4); //������ 0,1,2,3 �׸��� 4�� ��쿣 �ٽ� 0

		board[y][x] = 1; //���� ��ǥ

		while (g--) {
			int vsize = v.size();

			for (int j = vsize - 1; j >= 0; j--) { //���� Ž��
				v.push_back( (v[j]+1)%4 );       //+1 ���ϰ� %4 ������� �߰��� ����
			}
		}

		for (int i = 0; i < v.size(); i++) {
			int dir = v[i];
			if (dir == 0) x++;
			else if (dir == 1) y--;
			else if (dir == 2) x--;
			else if (dir == 3) y++;
			board[y][x] = 1;
		}

	}
	//
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (!board[i][j]) continue;
			// board[i][j]=1�� ��� �Ʒ� ���� ����
			//������ �� �� �˻��ؼ� ��� 1�̸� ���簢�� 1��
			if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) 
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}