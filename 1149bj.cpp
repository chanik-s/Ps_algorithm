#include <iostream>
#include <algorithm>
using namespace std;

int d[1005][5];
int R[1005];
int G[1005];
int B[1005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	//2���� ��ȭ�� ������ ���� ���� �߰�
	//d[i][0]: R
	//d[i][1]: G
	//d[i][2]: B
	for (int i = 1; i <= n; i++) {
		cin >> R[i] >> G[i] >> B[i]; //i��° �� ����, �ʷ�, �Ķ����� ĥ�ϴ� ���
	}

	//�ʱⰪ
	d[1][0]=R[1];
	d[1][1]=G[1];
	d[1][2]=B[1];
	//d[2][0]=;
	//d[2][1];
	//d[2][2];
	//�ּҺ�� ��ȭ��
	for (int i = 2; i <= n; i++) {
		d[i][0] = min(d[i-1][1],d[i-1][2]) + R[i];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + G[i];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + B[i];
	}

	//int mn = d[n][0];
	//mn = min(mn, d[n][1]);
	//mn = min(mn, d[n][2]);
	//cout << mn;

	cout << min({ d[n][0],d[n][1],d[n][2] }); //list�� 3�� �� ����.. {} �ȿ� ���� ���� �ֱ�! 
	return 0;
}