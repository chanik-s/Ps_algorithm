#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
int n, k;
int arr[12];
int cnt;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> arr[i];//오름차순
	}

	for (int i = n - 1; i >= 0; i--) {

		if (arr[i] > k) continue;

		cnt += k / arr[i];
		if (k == 0) break;
		k = k % arr[i];
	}

	cout << cnt;

	return 0;
}