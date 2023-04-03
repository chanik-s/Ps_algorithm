#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;

string maze[1002];
//bool vis[1002][1002]; //0또는 1
int dist1[1002][1002]; //불 전파시간 
int dist2[1002][1002]; //지훈이 이동시간
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	queue <pair <int, int> > q1; //불
	queue <pair <int, int> > q2; //지훈

	//입력
	for (int i = 0; i < r; i++)
	{
		fill(dist1[i], dist1[i] + c, -1);
		fill(dist2[i], dist2[i] + c, -1);
	}
	for (int j = 0; j < r; j++)
	{
		cin>> maze[j];
	}
		

	for (int j = 0; j <r; j++) {
		for(int i=0;i<c;i++){
			if (maze[j][i] == 'J') //J는 하나뿐
			{
	                            
				q2.push({ j,i }); //시작점 큐 넣기
				dist2[j][i] = 0;
			}
			if (maze[j][i] == 'F') {
				q1.push({ j,i }); //시작점 큐 넣기
				dist1[j][i] = 0; //원점->>0으로
			}
		}
		
	}

	//알고리즘 불
	while (!q1.empty()) {

		auto cur = q1.front(); q1.pop(); //예를 들어, cur={1,2}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir]; //first=1
			int ny = cur.second + dy[dir];//second=2
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (dist1[nx][ny] >= 0 || maze[nx][ny] == '#') continue;

			dist1[nx][ny] = dist1[cur.first][cur.second] + 1; //처음 'F'는 0(원점)이므로 한칸이동시 1
			q1.push({ nx,ny });
		}
	}
	//지훈
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir]; //first=1
			int ny = cur.second + dy[dir];//second=2
			
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				//범위 벗어남 ==> 외곽 탈출
				cout << dist2[cur.first][cur.second] + 1; //cur={3,1} dist2[][]=2 최종 3
				return 0;
			}
			if (dist2[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
			//벽은 안되고(!=-1)    불이 똑같거나 더빨리 도착하면 안됨 

			dist2[nx][ny] = dist2[cur.first][cur.second] + 1; //처음 'F'는 0(원점)이므로 한칸이동시 1
			q2.push({ nx,ny });
		}
		
	}
	cout << "IMPOSSIBLE";

	return 0;
}