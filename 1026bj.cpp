#include <iostream>
#include <algorithm>
using  namespace std;
int n;

int A[55];
int B[55];

int S() {
	int s=0;
	
	for (int i = 0; i < n; i++) {
		s += A[i] * B[i];
	}
	return s;
}
bool cmp(int a,int b){
	return a > b;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int mn = 101;
	cin >> n;

	for(int i=0;i<n;i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	//�ּڰ� ã��
	//�ʱ�) �������� ��ĭ�� �̵��ؼ� ��迭�� �ּڰ� ���ϱ� �׷��� �������� ���̽� ����
	// B�� ���� ���� Aū�� ��ġ�ؼ� ����
	
	sort(A, A + n); //��������
	sort(B, B + n, cmp);//��������

	mn = S();

	cout << mn;
	return 0;
}

/*
for (int count = 0; count < n;count++) {

	//S�� ���
	mn = min(mn, S());

	//A ��迭
	int tmp = A[0];
	for (int i = 0; i <= n - 2; i++) {
		A[i] = A[i + 1];
	}
	A[n - 1] = tmp;
}
*/
