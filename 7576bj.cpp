#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
//토마토
//여러 개 시작점에서 모든 지점으로의 거리 구하기
using namespace std;

int m, n;
int box[1002][1002]; //0초기화
int dist[1002][1002];//0초기화
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	queue <pair <int, int> > q;
	

	//box 각 좌표의 원소값들 입력 받고 각 좌표의 dist배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) q.push({ i,j }); //익은 토마토  ..여러개 bfs돌기(모든 시작점 큐에 넣기)
			if (box[i][j] == 0) dist[i][j] = -1; //익지 않은 토마토 ..dist배열을 -1로 초기화
			//익은,빈칸 -> dist값 자동으로 0 
		}
	}
	//bfs동작
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		//auto ->> pair<int,int> 자동으로
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first+dx[dir];
			int ny = cur.second+dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny>=m) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1; 
			//초기 위치에서의 거리와 방문처리 한번에 나타낼 수 있음.. dist배열
			q.push({ nx,ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) { //토마토 모두 익지 못하는 경우 
				cout << -1;  
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
	return 0;
}