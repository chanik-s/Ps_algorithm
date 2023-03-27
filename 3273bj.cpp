#include <bits/stdc++.h>

using namespace std;
int n;
int arr[100002];
int cnt;
int x;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	sort(arr, arr + n); //����
	cin >> x;
	//�� ������ �̿�
	int start=0; // ù��° ���� ����Ŵ
	int end =n-1;
	int temp = 0;
	while (start<end) {
		temp = arr[start] + arr[end];
		if (temp == x) {
			cnt++;
			start++;
			end--;
		}
		else if (temp < x) {
			start++; //x=100�̰� (1,98)�϶� start�� �������� ����� 100��
		}
		else end--; //�ݴ��� ��� end�� ���� --

	}
	/* 
	//�ð� �ʰ����� why? ���� for�������� �ð����⵵ O(n^2)
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <=n; j++) {
			
			if (x == (arr[i] + arr[j]))
			{
				cnt++;
			}
		}
	}
	*/ 

	cout << cnt;

	
	return 0;
}