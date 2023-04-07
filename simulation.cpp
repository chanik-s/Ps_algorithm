#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int board2[10][10]; //cctv 감시영역에 걸리는 빈칸은 대충 7로 설정
int n, m;
//int k = 0; //cctv 수 최대 8
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector <pair<int, int>> cctv; //cctv 좌표

bool OOB(int a, int b) { //범위 체크
	return a < 0 || a >= n || b < 0 || b >= m; //벗어나면 true 반환
}

void upd(int x, int y, int dir) { //감시영역 7값으로 체크해주는
	dir %= 4;
	while (1) {
		//dir(ex>dir=0,남쪽)이 정해지면 그 방향으로 쭈욱 가는?
		x += dx[dir]; 
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return; //범위 벗어나거나 벽이면 종료
		if (board2[x][y] != 0) continue; //해당칸 cctv있을때 넘어뜀
		board2[x][y] = 7; //감시영역 포함됨을 의미
	}
}
int main() {  
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>> n >> m; //세로 가로
	int mn = 0; //사각 지대 최소 크기(답)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; // 0빈칸   1~5 cctv     6벽
		
			if (board[i][j] != 0 && board[i][j] != 6)
				cctv.push_back({ i,j }); //cctv vector에 저장
			if (board[i][j] == 0) mn++; //초기엔 빈칸 개수 들어가
		}
	}
	
	//pow(4,k)에서 pow는 정수의 정수승 하면 오차 있을수있음 
	//cctv.size() : 벡터에 들어간 cctv개수(k개)
	//1<<2*cctv.size--> 2^(2*k) ==> 4^k       

	for (int tmp = 0; tmp < 1<<(2*cctv.size()); tmp++) { //cctv 3개일때 64가지 (0~4^3-1)
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board[i][j]; //board에 있는 값 일단 복사..board2[][]에는 7 넣어 감시 영역 표시
			}
		}
		int brute = tmp;//  임시 변수를 둬서 tmp 값을 옮겨담은 후 brute를 4로 나누는지를 고민
		
		for (int i = 0; i < cctv.size(); i++) { //3대 ==>k

			int dir = brute % 4;       //4진법 통해 나머지값으로 방향(0,1,2,3) 설정 
			brute /= 4;

			int x = cctv[i].first;
			int y = cctv[i].second;
			if (board[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (board[x][y] == 2) {
				upd(x, y, dir);
				upd(x, y, dir + 2);
				//2가지 방향
				//(0,2):(아래,위)     (1,3):(오른,왼)  (2,4%4):(위,아래)   (3,5%4):(왼,오)
			}
			else if (board[x][y] == 3) {
				upd(x, y, dir);
				upd(x, y, dir + 1); //직각
			}
			else if (board[x][y] == 4) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
			}
			else //board[][]==5
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
		} //모든 cctv에대해서 감시영역 표시 설정끝

			int sum = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					sum += (board2[i][j] == 0); //()조건이 참이면 +1 :감시영역 피해간 사각지대
				}
			}
			mn = min(mn, sum);	
	}
	cout << mn;

	return 0;
}