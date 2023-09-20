#include <iostream>

using namespace std;
int n;
int d[1000005]; //N�� �ش��ϴ� 10^6 ���� ������ ���� "���� Ƚ��"�� ���� ���̺� ����

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	d[1] = 0; //����Ƚ�� �ʱⰪ [1�� 1�� ����� ���� ����Ƚ�� 0ȸ]

	//���̺� ä��� d[12]=? d[1]~d[11]���� ���̺� ä������ �ľǰ���
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 3 == 0) d[i] = min(d[i],d[i / 3] + 1);
		if (i % 2 == 0) d[i] = min(d[i],d[i / 2] + 1);
	}
	cout << d[n];

	return 0;
}