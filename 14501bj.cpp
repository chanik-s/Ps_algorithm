#include <iostream>

using namespace std;

int n;

int d[20];
int t[20];
int p[20];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++) { //1�������� n��������
		cin >> t[i] >> p[i];
	}

	// �ʱ갪�� ���� n=7 ������ ��� ,d[8]=0��
	 
	//dp���(���� �� ����ϱ� ���α׷���!)
	//������������ ����
	for (int i = n; i >= 1; i--) {
		//deadline=i+t[i]
		if (i + t[i] <= n + 1) { //������� 5���� + 3��(���Ⱓ)�̸� 7������ ����(n+1=8 ��������) 

			d[i] = max( d[i+t[i]] + p[i], d[i+1]); //�Ųٷ� ���Ƿ� d[i+1]�� ���� �� 
		}
		else {
			d[i] = d[i + 1]; //���Ұ� ������ �״�� , �������� �ε���(i)�� �ϳ� ū ��
		}
	}

	cout << d[1]; //������ ������ �Ųٷ� ����
	return 0;
}