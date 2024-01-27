#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];//각 로프가 버틸수 있는 최대 중량
	}

	sort(a, a + n); //로프가 버틸수 있는 중량 대로 정렬( 각 수보다  w/k가 크면 끊어져)
	int ans = 0;
	for (int i = 1; i <= n;i++) {
		ans = max(ans, a[n - i] * i); //a[0] ~a[n-1]
		//i=1,n=10, a[]={1,2,3,4,5,6,7,8,9,10}
		//ans => a[10-10]*10 =10 .. 10개 로프로 무게 감당가능 그러나 10개 로프로 1 무게만

		//i=5,n=10, a[]={동일}
		//ans=> a[10-5]*5= 6*5=30 .. 5개 로프로 무게 감당 6의 무게씩
		// (따라서 1,2,3,4,5 무게만 감당가능한 로프는 못써)
	}

	cout << ans;

	return 0;
}