#include <iostream>

using namespace std;
int a[15];

int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int tmp = k;
	int cnt = 0;

	for (int j = n; j >= 1; j--) {
		if (a[j] > k) continue;
		int s = 0;
		s = tmp / a[j];
		cnt += s;
		if (tmp % a[j] == 0) break;
		tmp = tmp % a[j];

	}
	cout << cnt;
	return 0;
}
