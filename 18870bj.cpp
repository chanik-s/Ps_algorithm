#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
//n=100만 => O(nlogn)허용
//n=5000 => O(n^2) 허용
int X[1000005]; 
vector<int> tmp,X2; //정렬 담을 배열 과 중복 제거된 배열 담을 배열
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> X[i];
		//tmp.push_back(X[i]);
		X2.push_back(X[i]);
	}
	sort(X2.begin(), X2.end());

	//unique(): 중복 제거된 원소들 모아주고 다음 값 itertator 가리켜 by STL
	//erase() : first ,Last 쓰레기값 원소 제거
	X2.erase(unique(X2.begin(), X2.end()) , X2.end());
	/*
	//정렬
	sort(tmp.begin(), tmp.end());
	
	//int cnt = 0;
	//중복제거
	for (int i = 0; i < n; i++) {
		if (i != 0&& tmp[i - 1] == tmp[i])
		{	
			//cnt++;
			;
		}
		else {
			//cnt = 1;
			X2.push_back(tmp[i]);
		}
	}
	*/

	//X2[] 인덱스 자체가 Xi>Xj 만족하는 개수와 같음
	for (int i = 0; i < n; i++) {
		cout << lower_bound(X2.begin(),X2.end(),X[i])-X2.begin()<<' ';
	}

	return 0;
}