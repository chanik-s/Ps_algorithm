#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int m, n, k;

int board[105][105]; //격자의 경우는 x,y축 기존 개념대로 
int vis[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> m >> n >> k;

	while (k--) { //뒤집은 모습(x,y바꾼) 직사각형 색칠 작업
		int x, y;
		cin >> x >> y;
		//board[y][x] = 1; //색칠
		int xx, yy;
		cin >> xx >> yy;
		//board[yy][xx] = 1;
		for (int i = y; i <= yy-1; i++) {
			for (int j = x; j <= xx-1; j++) {
				board[i][j] = 1;//직사각형 색칠
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
			
			if (vis[i][j] || board[i][j] != 0) continue; //0인곳만 탐색

			vis[i][j] = 1; // 시작점 방문 처리
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