#include <iostream>
#include <algorithm>

using namespace std;
long long arr[100002];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int cnt = 0; //���� '���� �ִ� ��' �� �� ����?
	//������� ���� ���� ������ ���� '��'
	long long mxval = -(1LL << 62) - 1; // LL����ȯ ���ϸ� int overflow  '1'
	int mxcnt = 0; //������� ���� ���� ������ ���� '���� Ƚ��'

	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {

		if (i == 0 || arr[i-1] == arr[i] ) cnt++;
		//i==0�� true�̸� �� arr[i-1] �Ǵ� ���ص� true

		else { //���ο� �� ����� ����
			//���� ���� �ִ� ��(arr[i])�� ������ �ٸ���
			if (cnt > mxcnt) { //���� ���� ������ �ִ� ������ ����� ����
				mxcnt = max(cnt, mxcnt);
				mxval = arr[i - 1]; //������ �߱⿡ 
			}
			cnt = 1; //���� ���� �� ����Ƚ��
		}

	}
	//������ ���� ������Ʈ �ȵǴ� ������ ����..
	//������ ���� ���� cnt
	if (cnt > mxcnt)
		mxval = arr[n - 1];//����
	cout << mxval;


	return 0;
}