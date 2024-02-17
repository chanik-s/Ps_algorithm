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


		mid = (left + right) / 2; //간격 ex>(10~50)휴게소 사이에 3(mid)씩 띄어서 짓는다
		
		int cnt = 0; //새롭게 추가할 (휴게소 사이 배치될수있는) "휴게소 개수"

		for (int i = 1; i < (int)v1.size(); i++) { // v1[0]과 v1[n+1]은 0과 L 
			int dist = v1[i] - v1[i - 1]; //v1[1]-v1[0]:첫번째 구간

		
				cnt += (dist / mid); //들어갈 수 있는 휴게소 최대 개수
				//ex> 40/3=13개 짓기 가능
				if (dist % mid == 0) { //휴게소 이미 있는 위치라면
					cnt--;
					//ex> (10~15)휴게소 사이 1(mid)씩 띄어서 짓는다?
					// 10 11 12 13 14 15
					// dist=5 mid=1 가정시
					// cnt=5개 지을수 있다 하지만 기존 휴게소는 10 15이다.
					//따라서, 11 12 13 14 4개만 지을수 있게 cnt--가 필요하다.
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
