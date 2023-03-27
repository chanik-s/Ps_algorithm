#include <bits/stdc++.h>

using namespace std;
int n;
int arr[100002];
int cnt;
int x;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	sort(arr, arr + n); //정렬
	cin >> x;
	//투 포인터 이용
	int start=0; // 첫번째 원소 가리킴
	int end =n-1;
	int temp = 0;
	while (start<end) {
		temp = arr[start] + arr[end];
		if (temp == x) {
			cnt++;
			start++;
			end--;
		}
		else if (temp < x) {
			start++; //x=100이고 (1,98)일때 start를 다음꺼로 해줘야 100됨
		}
		else end--; //반대의 경우 end를 감소 --

	}
	/* 
	//시간 초과에러 why? 이중 for문때문에 시간복잡도 O(n^2)
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <=n; j++) {
			
			if (x == (arr[i] + arr[j]))
			{
				cnt++;
			}
		}
	}
	*/ 

	cout << cnt;

	
	return 0;
}