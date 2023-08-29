#include <iostream>

using namespace std;
int n, m;
int board[22][22];//지도의 한 칸은 정수값
int x, y,k;


int dice[7]; //인덱스 1~6쓸려고 0~5대신..그대신 0인덱스는 안쓰는것=> dice[0]은 의미없음
// {0, 1,2,3,4,5,6}  2는 윗면 6은 동쪽 4는 바닥
//      [1]
//  [5] [2] [6]
//      [3]
//      [4]

int idx[5][4] = {
	{}, //dummy.. 쓰지 않음
	{2,6,4,5}, //동(dir=1)
	{2,5,4,6}, //서
	{3,2,1,4}, //북
	{2,3,4,1} //남
};

void roll(int dir) {//dir=1~4임
	//회전시 기존 주사위 값 보존하기위한 배열
	int tmp[7]; //인덱스 1~6 사용할려고 0~5대신.. tmp[0]는 무시됨
	 
	for (int i = 1; i <= 6; i++) tmp[i] = dice[i]; //주사위 값 6개 복사

	//굴림--4개만 변경..방향이 어디든 2개는 고정됨 (주사위값중 2개는 변경없음)
	for (int i = 0; i < 4; i++) {
		tmp[idx[dir][(i + 1) % 4]] = dice[idx[dir][i]]; //idx[][0~3만 가능이므로 나머지계산]
	}

	for (int i = 1; i <= 6; i++) dice[i] = tmp[i];

}
bool check(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	else
		return true;
}

void move(int dir) { //동서남북 중 하나 명령 받아와서 이동
	//예시에서는 남쪽으로 한칸 이동한 상태임
	int nx = x, ny = y;
	//일단 이동하고
	if (dir == 4) //남쪽
	{
		nx = nx + 1;
	} //주사위 위치변경
	else if (dir == 3) //북쪽
	{
		nx = nx - 1;
	}
	else if (dir == 2) //서
		{ny = ny -1;}
	else if (dir == 1) //동 
		{ny = ny +1;}
	
	if (check(nx, ny)) {//범위 벗어나지않아야
		x = nx; y = ny; //주사위 위치 바꿔놓아야함

		roll(dir);

		//이동한 칸의 값에 따라 분류
		if (board[nx][ny] == 0) {

			board[nx][ny] = dice[4];
		}
		else {
			dice[4] = board[nx][ny];//칸에 쓰여 있는 수가 주사위의 바닥면으로 복사
			board[nx][ny] = 0;
		}

		cout<<dice[2]<<endl; //윗면	
	}
	//벗어나면 출력 x

	
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//입력
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; //NxM 지도에 쓰여있는 수
			//주사위를 놓은 칸에 쓰여 있는 수는 항상 0 -->예시에서는 (0,0) 좌표의 값이 0
		}
	}
	for (int i = 0; i < k; i++) { //k개의 명령
		int dir;
		cin >> dir; //동쪽 1 서쪽 2 북쪽 3 남쪽  4
		//알고리즘
		move(dir);
	}
	

	//출력

	return 0;
}