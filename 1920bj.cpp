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

	sort(a, a + n); //���� �켱������
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int ans = 0;
		cin >> b[i]; //b[i]�� a�ȿ� �����ϴ���!?

		//�̺�Ž���� ���̴� �� ���� [����]
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
		

		//����� ans=1 , �ƴϸ� 0

		cout << ans << '\n';
	}

	return 0;
}