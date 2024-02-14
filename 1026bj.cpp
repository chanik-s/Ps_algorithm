#include <iostream>
#include <algorithm>
using  namespace std;
int n;

int A[55];
int B[55];

int S() {
	int s=0;
	
	for (int i = 0; i < n; i++) {
		s += A[i] * B[i];
	}
	return s;
}
bool cmp(int a,int b){
	return a > b;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int mn = 101;
	cin >> n;

	for(int i=0;i<n;i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	//최솟값 찾기
	//초기) 왼쪽으로 한칸씩 이동해서 재배열한 최솟값 구하기 그러나 생각못한 케이스 존재
	// B의 작은 수에 A큰거 배치해서 곱해
	
	sort(A, A + n); //오름차순
	sort(B, B + n, cmp);//내림차순

	mn = S();

	cout << mn;
	return 0;
}

/*
for (int count = 0; count < n;count++) {

	//S값 계산
	mn = min(mn, S());

	//A 재배열
	int tmp = A[0];
	for (int i = 0; i <= n - 2; i++) {
		A[i] = A[i + 1];
	}
	A[n - 1] = tmp;
}
*/
