#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
int n, m;
//int a[500005];
//int cnt[500005];

int lower_idx(int t,int len) {
	int st = 0, en = len;

	while (st < en) {

		int mid = (st + en) / 2;
		if (a[mid] >= t) {
			en = mid;
		}
		else {
			st = mid + 1;
		}
	}
	return st;
}
int upper_idx(int t, int len) {
	int st = 0, en = len;

	while (st < en) {

		int mid = (st + en) / 2;

		
		if (a[mid] > t) {
			en = mid;
		}
		else { //a[mid]==target
			st = mid + 1;
		}
	}
	return st;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t; //target ex>10
		cout << upper_idx(t, n)-lower_idx(t,n)<<' ';
		
	}
	/*
	vector<int> cnt(m);

	for (int i = 0; i < m; i++) {

		int t;
		cin >> t; //비교할 숫자
		
		vector<int>::iterator low, up;
		low = lower_bound(a.begin(), a.end(), t);
		up = upper_bound(a.begin(), a.end(), t);

		int count = ((up - a.begin()) - (low - a.begin()));
		cnt[i] = count;
	}

	for (auto &i : cnt) {
		cout << i << ' ';
	}
	*/
	return 0;
}