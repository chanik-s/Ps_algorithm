#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int m, n, k;

int board[105][105]; //������ ���� x,y�� ���� ������ 
int vis[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> m >> n >> k;

	while (k--) { //������ ���(x,y�ٲ�) ���簢�� ��ĥ �۾�
		int x, y;
		cin >> x >> y;
		//board[y][x] = 1; //��ĥ
		int xx, yy;
		cin >> xx >> yy;
		//board[yy][xx] = 1;
		for (int i = y; i <= yy-1; i++) {
			for (int j = x; j <= xx-1; j++) {
				board[i][j] = 1;//���簢�� ��ĥ
			}
		}
	}
	/*
	for (int i = 0; i < m;i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j]<<' ';
		}
		cout << '\n';
	}*/
	queue<pair<int, int> > q;
	
	vector<int> area;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			
			if (vis[i][j] || board[i][j] != 0) continue; //0�ΰ��� Ž��

			vis[i][j] = 1; // ������ �湮 ó��
			q.push({ i,j });
			cnt++;
			int areacnt = 0;
			while (!q.empty()) {

				auto cur = q.front(); q.pop();
				areacnt++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
					if (vis[nx][ny]||board[nx][ny]!=0) continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				}

			}
			area.push_back(areacnt);
		}
	}
	sort(area.begin(), area.end());

	cout << cnt<<'\n';
	for (auto a : area) {
		cout << a<<' ';
	}
	return 0;
}