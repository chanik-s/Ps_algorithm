#include <bits/stdc++.h>

using namespace std;

int N;
int A[505][505];
//동 x그대로 y증가 (오른쪽)
//서 x그대로 y감소 (왼쪽)
//남 x증가 y 그대로 (아래)
//북 x감소 y 그대로 (위)
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer;  //격자밖으로 이동 모래양

//4=>동 서 남 북 순으로 매핑
//동쪽 기준 :  {1,1,7,7,10,10,2,2,5,a} 순으로 10개 존재
//[0]:동쪽 [1]:서쪽 [2]:남쪽 [3]: 북쪽
int  xdx[4][10] = { {-1,1,-1,1,-1,1,-2,2,0,0},{-1,1,-1,1,-1,1,-2,2,0,0},
	{0,0,1,1,2,2,1,1,3,2},{0,0,-1,-1,-2,-2,-1,-1,-3,-2} };
int ydy[4][10] = { {0,0,1,1,2,2,1,1,3,2},{0,0,-1,-1,-2,-2,-1,-1,-3,-2},
	{-1,1,-1,1,-1,1,-2,2,0,0},{-1,1,-1,1,-1,1,-2,2,0,0} };
int percent[9] = { 1,1,7,7,10,10,2,2,5 }; //비율

int change_dir(int Dir) {       //->
	if (Dir == 0) return 3; //동     북
	if (Dir == 1) return 2; //서     남
	if (Dir == 2) return 0; //남     동
	if (Dir == 3) return 1; //북     서
}

void Spread_Sand(int x,int y,int Dir) { //Dir=>동서남북
	int xx = x + dx[Dir];
	int yy = y + dy[Dir];
	if (A[xx][yy] == 0) return; //이동한 곳(문제에서 y)의 모래양이 0이면 비율 나눠줘도 0
	
	int Sand = A[xx][yy]; //모래양
	int Tmp = Sand;
	for (int i = 0; i < 9; i++) { //동서남북에 따라 다른 좌표 탐색   9개만 해줌.. 알파a에 대한건 따로
		int nx = x+xdx[Dir][i];
		int ny = y+ydy[Dir][i];
		int Per = percent[i];
		int Plus = (Tmp * Per) / 100;

		if (nx < 1 || ny < 1 || nx > N || ny > N) 
			answer += Plus;
		else
			A[nx][ny] += Plus;

		Sand -= Plus; //비율 적히지 않은 남은 모래 양 (비율로 구해진 Plus모든값 빼주면 남은것)
	}
	//마지막 좌표 a알파에 대한 것
	int nx = x + xdx[Dir][9];
	int ny = y + ydy[Dir][9];

	if (nx < 1 || ny < 1 || nx > N || ny > N) answer += Sand; //격자밖으로 이동 모래양
	else A[nx][ny] += Sand; //모래가 이미 있는 칸으로 모래가 이동하면, 모래의 양은 더해진다. 
	
	A[xx][yy] = 0; //왜??
}
void Solution() {
	int Dir = 1; //서쪽 방향 첫번째임!
	int move_cnt=1;
	//시작 (N/2 + 1 , N/2 + 1)
	int x = (N / 2) + 1;
	int y = (N / 2) + 1;

	while (1) {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < move_cnt; j++) {  //토네이도가 움직여야 하는 칸수인 move_cnt
				Spread_Sand(x, y, Dir); //서쪽(Dir=1)으로 시작
				//좌표 이동  (처음엔 왼쪽으로)
				x += dx[Dir];
				y += dy[Dir];
			}
			Dir = change_dir(Dir); // 서->남->동->북 계속 한 턴마다 방향 바꾸고

		} //2번 반복

		move_cnt++; // 1칸 2번 2칸 2번 ...  6칸 2번 ...
 		if (move_cnt == N) { //7칸일때
			
			for (int j = 0; j < move_cnt; j++) {  //토네이도가 움직여야 하는 칸수인 move_cnt
				Spread_Sand(x, y, Dir); 
				//좌표 이동 
				x += dx[Dir];
				y += dy[Dir];
			}
			break;
		}

	}
	cout << answer << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; //홀수 ex>7
	for (int i = 1; i <= N; i++) {   //1~N까지
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j]; // 모래 양
		}
	}
	
	Solution();

	return 0;
}