#include <iostream>
#include <algorithm>

using namespace std;
long long arr[100002];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int cnt = 0; //현재 '보고 있는 수' 몇 번 등장?
	//현재까지 가장 많이 등장한 수의 '값'
	long long mxval = -(1LL << 62) - 1; // LL형변환 안하면 int overflow  '1'
	int mxcnt = 0; //현재까지 가장 많이 등장한 수의 '등장 횟수'

	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {

		if (i == 0 || arr[i-1] == arr[i] ) cnt++;
		//i==0이 true이면 뒤 arr[i-1] 판단 안해도 true

		else { //새로운 수 등장시 실행
			//현재 보고 있는 수(arr[i])가 이전과 다를때
			if (cnt > mxcnt) { //가장 많이 가지고 있는 정수를 출력이 목적
				mxcnt = max(cnt, mxcnt);
				mxval = arr[i - 1]; //정렬을 했기에 
			}
			cnt = 1; //새로 나온 수 등장횟수
		}

	}
	//마지막 수는 업데이트 안되는 구조라 따로..
	//마지막 수에 대한 cnt
	if (cnt > mxcnt)
		mxval = arr[n - 1];//끝값
	cout << mxval;


	return 0;
}