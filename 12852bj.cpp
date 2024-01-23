#include <iostream>

using namespace std;
int d[1000005];
int pre[1000005]; //��� ���� .. �߰����� ������ ���� 
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	d[1]=0;
	pre[1] = 0;

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1; //d[i]�� ��� �ϴ� �ϰ� 
		pre[i] = i - 1; //�ϴ� �ϰ� 
		
		if (i % 3 == 0 && d[i]>d[i/3]+1) //�� ������(�ּڰ�) ������ 
		{ 
			d[i] = d[i / 3] + 1; //d[i]�� ����
			pre[i] = i / 3; //������ �����
		}

		if (i % 2 == 0 && d[i]>d[i/2]+1) {
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2; //������ �����
		}
		//�� if�� ���� �ٲٸ� ��� �ٲ�� ����!
	}
	cout << d[n] << '\n';
	int cur = n;
	while (1) {
		cout << cur << ' '; //���� ���
		if (cur == 1) break;
		cur = pre[cur];
	}

	return 0;
}