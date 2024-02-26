#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int b[100005];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n); //정렬 우선적으로
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int ans = 0;
		cin >> b[i]; //b[i]가 a안에 존재하는지!?

		//이분탐색에 쓰이는 두 변수 [범위]
		int st = 0;
		int en = n-1;

		while (st <= en) {
			
			int mid = (st + en) / 2;

			if (a[mid] == b[i])
			{
				ans = 1;
				break;
			}
			else if (a[mid] < b[i]) {
				st = mid + 1;
			}
			else {
				en = mid - 1;
			}

		}
		

		//존재시 ans=1 , 아니면 0

		cout << ans << '\n';
	}

	return 0;
}