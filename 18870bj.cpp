#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
//n=100�� => O(nlogn)���
//n=5000 => O(n^2) ���
int X[1000005]; 
vector<int> tmp,X2; //���� ���� �迭 �� �ߺ� ���ŵ� �迭 ���� �迭
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> X[i];
		//tmp.push_back(X[i]);
		X2.push_back(X[i]);
	}
	sort(X2.begin(), X2.end());

	//unique(): �ߺ� ���ŵ� ���ҵ� ����ְ� ���� �� itertator ������ by STL
	//erase() : first ,Last �����Ⱚ ���� ����
	X2.erase(unique(X2.begin(), X2.end()) , X2.end());
	/*
	//����
	sort(tmp.begin(), tmp.end());
	
	//int cnt = 0;
	//�ߺ�����
	for (int i = 0; i < n; i++) {
		if (i != 0&& tmp[i - 1] == tmp[i])
		{	
			//cnt++;
			;
		}
		else {
			//cnt = 1;
			X2.push_back(tmp[i]);
		}
	}
	*/

	//X2[] �ε��� ��ü�� Xi>Xj �����ϴ� ������ ����
	for (int i = 0; i < n; i++) {
		cout << lower_bound(X2.begin(),X2.end(),X[i])-X2.begin()<<' ';
	}

	return 0;
}