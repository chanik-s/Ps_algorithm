//�ϳ���ž
#include <bits/stdc++.h>

using namespace std;

//void func(int n) { //n���� ���1->���3 �ű�� ��� ���
void func(int a,int b,int n){ //n���� a�� ��տ��� b�� ������� �Ű�
	                          //����� 1����տ��� 3�� ������� �ű�� ��

	
	//���..base condition(1������ ���1���� ���3����)
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	//n-1���� ���1���� ���2�� , n�������� ���3����
	func(a, 6 - a - b, n-1);
	//n�� ���� ���a->b
	cout << a << ' ' << b << '\n';
	//n-1���� ��� 2���� ���3���� 
	func(6 - a - b, b, n - 1);

}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; //���ǰ���
	//�ű� Ƚ��
	cout << (1 << n) - 1 << '\n'; //��Ʈ������ 1�� ��Ʈ ���� ���� nĭ �о� 
	func(1, 3, n);
	
	return 0;
}