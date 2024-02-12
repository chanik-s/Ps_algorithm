#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define first X
#define second Y
// 우측 x 축 , 아래 y축
//d=0 오 1 위 2 왼 3 아
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

int board[105][105]; //100x 100 판
int n;
int x, y, d, g;
int cnt;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) { //n개의 각각의 드래곤 커브
		cin >> x >> y >> d >> g;
		
		vector<int> v; //방향 정보
		v.push_back(d % 4); //방향은 0,1,2,3 그리고 4의 경우엔 다시 0

		board[y][x] = 1; //시작 좌표

		while (g--) {
			int vsize = v.size();

			for (int j = vsize - 1; j >= 0; j--) { //역순 탐색
				v.push_back( (v[j]+1)%4 );       //+1 더하고 %4 계산으로 추가된 방향
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
			// board[i][j]=1인 경우 아래 조건 실행
			//나머지 세 곳 검사해서 모두 1이면 정사각형 1개
			if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) 
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}