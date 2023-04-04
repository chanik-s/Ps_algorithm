#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int m, n;
pair<int, int> red, blue;
string board[11];
//dist[a][b][c][d]: 빨간구슬 (a,b)좌표 , 파란구슬 (c,d)좌표에 도달하기 위한 동작 횟수
int dist[11][11][11][11]; //거리 계산
//오 아래 왼 위
int dx[4] = { 0,1,0,-1 };
int dy[4] = {1,0,-1,0};

int bfs() {
	//파라미터 3개이상일경우 튜플 이용
	queue<tuple<int, int, int, int> > q;
	q.push({ red.X,red.Y,blue.X,blue.Y }); //4개 원소 있는 튜플 형태로 저장
	dist[red.X][red.Y][blue.X][blue.Y]=0;

	while (!q.empty()) {
		int rx, ry, bx, by; //현재 구슬의 x,y 좌표
		tie(rx, ry, bx, by) = q.front();//front()를 통해 튜플형태로 return되는데 이를 변수로 받고 싶을때
		                                //tie()를 써서 이미 선언된 rx,ry,bx,by에 변수로 하나씩 들어감
		q.pop();
		int cnt = dist[rx][ry][bx][by]; //return될 요소
		//10번안에 못하면 -1
		if (cnt >= 10)
			return -1;
		//4방향 기울이기
		for (int i = 0; i < 4; i++) { //한 방향에 대해 Red Blue 함께 이동
			int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by; 
			//움직였을때 바뀐 구슬의 x,y좌표.. 초기화는 현재 좌표

			//Blue 이동
			   //상하좌우움직일텐데 '.'만나야만 이동가능임

			//기울이면 벽 만날때까지 쭈우우욱 이동 그래서 while문
			while (board[n_bx + dx[i]][n_by + dy[i]] == '.') { //#나 O 만나기 전까지 반복해서 이동
				n_bx += dx[i]; //움직였을시 구슬 위치
				n_by += dy[i];
			}
			//Blue 탈출시 실패
			if (board[n_bx + dx[i]][n_by + dy[i]] == 'O') continue; //실패는 통과시켜(성공 케이스만)

			//Red 이동
			while (board[n_rx + dx[i]][n_ry + dy[i]] == '.') {
				n_rx += dx[i];
				n_ry += dy[i];
			}
			//Red 탈출시 종료 정답 반환
			if (board[n_rx + dx[i]][n_ry + dy[i]] == 'O') return cnt + 1;//왜 +1?

			//동일 행,열 상에서 Red,blue 겹쳐짐->늦게 출발한 구슬 한칸 뒤
			if ((n_rx == n_bx) && (n_ry == n_by)) {
				if (i == 0) { //오른쪽 
					ry < by ? n_ry-- : n_by--;
				}
				else if (i == 1) { //아래
					rx < bx ? n_rx-- : n_bx--;
				}
				else if (i == 2) { //왼
					ry > by ? n_ry++ : n_by++;
				}
				else //위
					rx > bx ? n_rx++ : n_bx++;
			}

			//이미 (n_rx, n_ry, n_bx , n_by) 방문했으면 통과
			if (dist[n_rx][n_ry][n_bx][n_by] != -1) continue;
			dist[n_rx][n_ry][n_bx][n_by] = cnt + 1; //방문하지 않았다면
			q.push({ n_rx, n_ry, n_bx , n_by });

		}


	}
	return -1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				fill(dist[i][j][k], dist[i][j][k] + 10, -1); //미방문: 거리 -1로 초기화
			}
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'B') {
				blue = { i,j };
				board[i][j] = '.';//?왜      기울여서 다시 갈 수 있는 곳으로 생각해서 ??
			}
			else if (board[i][j] == 'R') {
				red = { i,j }; //현재 구슬 위치 좌표 저장해두고
				board[i][j] = '.'; //갈 수 있는 칸으로 인식하게
			}
		}

	}

	cout << bfs(); //4차원 bfs돌리기

	return 0;
}