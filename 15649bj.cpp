#include <iostream>
//백트래킹 시작(전형적인 구조)
using namespace std;

int arr[10]; //수열을 담는 배열 M<=8이므로 공간 조금더 확보해서 10으로
bool issued[10]; //특정 수(1~8)가 쓰였는지 true(쓰임)/false(안쓰임)..issued[1]부터시작
int n, m;
//1-n 자연수 중에서 m개짜리 수열
void func(int k) {	// 현재 k개까지 수를 택했음.
	//base condition
	if (k == m) {	// m개를 모두 택했으면(m개짜리 수열 완성시)
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' '; // arr에 기록해둔 수를 출력(ex>123)
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {  // 1부터 n까지의 수에 대해 (ex>n=4 )
		if (!issued[i]) { // 아직 i가 사용되지 않았으면 (false)
			arr[k] = i;   // k번째 수를 i로 정함
			//arr[0]=1;(k=0일때,초기)
			issued[i] = 1; // i를 사용되었다고 표시(true)
			func(k + 1); //재귀--다음 수를 정하러 한 단계 더 들어감
			//예를 들어, 수열 123 다 찬 상태(k=3 m=3일때)이면 베이스 조건 실행후 리턴하므로 
			//돌아갈때 아래처럼 issued[3]=false; 실행가능
			issued[i] = 0;  // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
			//위 한 줄 코드는 func(k+1)이 리턴해야만 실행되는 것임 
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);//빈 수열에서 시작(재귀)

	return 0;
}