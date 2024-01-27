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
		cin >> a[i];//�� ������ ��ƿ�� �ִ� �ִ� �߷�
	}

	sort(a, a + n); //������ ��ƿ�� �ִ� �߷� ��� ����( �� ������  w/k�� ũ�� ������)
	int ans = 0;
	for (int i = 1; i <= n;i++) {
		ans = max(ans, a[n - i] * i); //a[0] ~a[n-1]
		//i=1,n=10, a[]={1,2,3,4,5,6,7,8,9,10}
		//ans => a[10-10]*10 =10 .. 10�� ������ ���� ���簡�� �׷��� 10�� ������ 1 ���Ը�

		//i=5,n=10, a[]={����}
		//ans=> a[10-5]*5= 6*5=30 .. 5�� ������ ���� ���� 6�� ���Ծ�
		// (���� 1,2,3,4,5 ���Ը� ���簡���� ������ ����)
	}

	cout << ans;

	return 0;
}