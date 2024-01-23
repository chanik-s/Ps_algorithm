#include <iostream>

using namespace std;
int d[1000005];
int pre[1000005]; //경로 복원 .. 추가적인 정보를 기입 
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	d[1]=0;
	pre[1] = 0;

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1; //d[i]값 계산 일단 하고 
		pre[i] = i - 1; //일단 하고 
		
		if (i % 3 == 0 && d[i]>d[i/3]+1) //더 작은거(최솟값) 나오면 
		{ 
			d[i] = d[i / 3] + 1; //d[i]값 변경
			pre[i] = i / 3; //만족시 덮어쓰기
		}

		if (i % 2 == 0 && d[i]>d[i/2]+1) {
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2; //만족시 덮어쓰기
		}
		//두 if문 순서 바꾸면 경로 바뀔수 있음!
	}
	cout << d[n] << '\n';
	int cur = n;
	while (1) {
		cout << cur << ' '; //현재 경로
		if (cur == 1) break;
		cur = pre[cur];
	}

	return 0;
}