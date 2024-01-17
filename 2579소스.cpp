#include <iostream>
#include <algorithm>
using namespace std;

int d[303][3];
int s[303]; //점수
int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i]; //i번째 계단 점수 입력
	if (n == 1) {
		cout << s[1]; //하나인경우 처음계단이 마지막계단 (무조건 밟아!)
		return 0;
	}
	//현재까지=>i번째 계단 밟은 기준에서 현재ㅎㅎ
	//D[i][1]는 현재까지 1개의 계단을 연속해서 밟고 
	//i번째 계단까지 올라섰을 때 점수 합의 최댓값입니다.
	// i-2번째 무조건 밟아

	//D[i][2]
	// i-1번째 무조건 밟아

	//초기값
	d[1][1] = s[1];
	d[1][2] = 0;
	d[2][1] = s[2];
	d[2][2] = s[1]+s[2];
	//나머지
	for (int i = 3; i <= n; i++) {
		d[i][1] = max(d[i-2][1],d[i-2][2])+s[i];
		d[i][2] = d[i-1][1]+s[i];
		//d[i-1][2]의 경우는 세번 연속하는 case
	}

	cout << max(d[n][1],d[n][2]);

	return 0;
}