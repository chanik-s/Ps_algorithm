#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int n, m,d; // d:방향  d=0 북 1 동 2 남 3 서
int board[55][55]; // [n] [m]
int cnt; //청소하는 칸 개수
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//북 동 남 서

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	int r, c; //초기 로봇 위치
	cin >> r >> c >> d; //인덱스 고려 필요없음

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {

		if (board[r][c]==0) { //현재 칸 청소되지 않은 빈칸(0)   <--> 벽 (1) 
			cnt++; //청소 횟수 증가
		}
		board[r][c] = -1;//청소됐을 경우 -1 
		
		bool cleaned = false; //네 방향중 청소된 곳 있는지

		for (int dir = 0; dir < 4; dir++) { //주변 4방향 반복
		
			//반시계 90 회전
			if (d == 0) d = 3;
			else if (d == 1) d = 0;
			else if (d == 2) d = 1;
			else d = 2;
			////앞쪽 칸 청소되지 않은 빈칸이면 전진
			if (board[r + dx[d]][c + dy[d]] == 0) {
				//전진
				r = r + dx[d];
				c = c + dy[d];

				//1번 돌아가
				cleaned = true; 
				break;
			}
		}
		
		if (cleaned) continue; //1번으로 돌아가기 위함
		//continue문으로 아래 코드 실행하지않고 다음 while문에서 시작

		// 네 방향중 청소되지 않은 빈칸 없는 경우==> 즉, for문에서 아무것도 안한거
		// 모두 청소됨 board[][]==-1
		if (board[r - dx[d]][c - dy[d]] == 1) //벽
			break; //작동 끝 while문 끝
		else {
			//후진		
			r = r - dx[d];
			c = c - dy[d];
		}
	}
	


	cout << cnt;

	return 0;
}