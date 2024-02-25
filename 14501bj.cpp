#include <iostream>

using namespace std;

int n;

int d[20];
int t[20];
int p[20];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++) { //1일차부터 n일차까지
		cin >> t[i] >> p[i];
	}

	// 초깃값에 의해 n=7 예제의 경우 ,d[8]=0임
	 
	//dp사용(이전 값 기억하기 프로그래밍!)
	//마지막날부터 생각
	for (int i = n; i >= 1; i--) {
		//deadline=i+t[i]
		if (i + t[i] <= n + 1) { //예를들어 5일차 + 3일(상담기간)이면 7일차에 끝남(n+1=8 까지가능) 

			d[i] = max( d[i+t[i]] + p[i], d[i+1]); //거꾸로 가므로 d[i+1]은 이전 값 
		}
		else {
			d[i] = d[i + 1]; //상담불가 이전값 그대로 , 이전값은 인덱스(i)가 하나 큰 값
		}
	}

	cout << d[1]; //마지막 날부터 거꾸로 했음
	return 0;
}