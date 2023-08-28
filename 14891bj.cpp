#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string board[4];//톱니바퀴 인덱스 0~3 , 4개
void f(int x,int dir) { //회전 처리  x=톱니바퀴 인덱스 , dir=방향

	int dirs[4] = {0,};//각 톱니바퀴들의 초기 방향
	dirs[x] = dir; //톱니바퀴 x의 방향 설정

	int idx = x;//톱니바퀴 인덱스 받아옴 0,1,2,3 중 하나
	//왼쪽 전파(인덱스가 1,2,3일때)
	//[idx][6]=>해당 톱니바퀴 9시 방향 [idx-1][2]=>왼쪽 옆 톱니바퀴 3시방향
	while (idx > 0 && board[idx][6] != board[idx - 1][2]) {//같으면 노회전
		
		dirs[idx - 1] = -dirs[idx];//왼쪽 애 방향반대로
		idx--;                     //갈 수 있으면 하나 더 반복
	}

	//오른쪽 전파(인덱스가 0,1,2일때)
	while(idx<3&&board[idx][2]!=board[idx+1][6])
	{
		dirs[idx + 1] = -dirs[idx];//오른쪽 애 방향 반대로
		idx++;
	}
	for (int i = 0; i < 4; i++) {//각 톱니바퀴마다 (dirs값에 따라)회전

		if (dirs[i] == -1) { //반시계
			rotate(board[i].begin(), board[i].begin() + 1, board[i].end());
			//함수의 가운데 요소(middle)가 첫 요소로 바뀜 
			// ex> v.begin() + 1 왼쪽 1칸이동
			//값들을 회전시키는 듯 지정된 횟수만큼 오른쪽으로 회전시키거나, 왼쪽으로 회전할 수 있다.
		}
		else if(dirs[i]==1) //시계
		{
			rotate(board[i].begin(), board[i].begin() + 7, board[i].end());
			// ex> v.begin() + 7 왼쪽 7칸이동 
			// ex> v.end()-1 오른쪽 1칸이동
		}
		//dirs[i]==0이면 노회전,,그대로
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++)
		cin >> board[i]; //톱니바퀴 상태저장 문자열 형태임 '10010101'

	int k;
	cin >> k; //회전 횟수
	
	for (int i = 0; i < k; i++) {

		int num, dir; //dir: 1 시계 -1 반시계

		cin >> num >> dir; //3 -1 일경우 3번 톱니바퀴(3) 반시계(-1) 이동

		f(num-1,dir); //회전..4번 톱니는 인덱스상 3이므로 num-1
	}//회전 끝

	//출력 점수 계산
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (board[i][0] == '0') //n극이면 0
		{
			ans += 0;
		}
	}
		if (board[0][0] == '1') {
			ans += 1 ;
		}
		if (board[1][0] == '1') {
			ans += 2;
		}
		if (board[2][0] == '1') {
			ans += 4;
		}
		if (board[3][0] == '1') {
			ans += 8;
		}


	cout << ans;

	return 0;
}