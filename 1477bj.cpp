#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n, m, L;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> L;

	
	vector<int> v1; //휴게소 위치 --> 1~(L-1)까지

	//특수케이스로 2개 추가하여 배열 개수 (n+2)
	v1.push_back(0);
	v1.push_back(L); //첫과 끝지점 모두 휴게소로 인지

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k; //휴게소 값
		v1.push_back(k); 
	}

	sort(v1.begin(), v1.end()); //고속도로 숫자 작은것부터 큰거로 이동하니 일렬로 배치

	//휴게소 사이 "거리(mid)"로 이분 탐색
	// 고속도로 끝에는 못지음 <--left ,right 초깃값 잘 생각
	int left = 1;
	int right = L-1;
	int mid;
	int ans = 1000;

	while (left <= right) {


		mid = (left + right) / 2;
		
		int cnt = 0; //새롭게 추가할 (휴게소 사이 배치될수있는) "휴게소 개수"

		for (int i = 1; i < (int)v1.size(); i++) { // v1[0]과 v1[n+1]은 0과 L 
			int dist = v1[i] - v1[i - 1]; //v1[1]-v1[0]:첫번째 구간

		
				cnt += (dist / mid);
				if (dist % mid == 0) { //휴게소 이미 있는 위치라면
					cnt--;
				}
			
		}

		if (cnt > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			ans = min(mid,ans);
		}
		

	}
	cout << ans << endl;

	
	return 0;
}