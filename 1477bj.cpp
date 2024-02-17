#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n, m, L;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> L;

	
	vector<int> v1; //�ްԼ� ��ġ --> 1~(L-1)����

	//Ư�����̽��� 2�� �߰��Ͽ� �迭 ���� (n+2)
	v1.push_back(0);
	v1.push_back(L); //ù�� ������ ��� �ްԼҷ� ����

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k; //�ްԼ� ��
		v1.push_back(k); 
	}

	sort(v1.begin(), v1.end()); //��ӵ��� ���� �����ͺ��� ū�ŷ� �̵��ϴ� �Ϸķ� ��ġ

	//�ްԼ� ���� "�Ÿ�(mid)"�� �̺� Ž��
	// ��ӵ��� ������ ������ <--left ,right �ʱ갪 �� ����
	int left = 1;
	int right = L-1;
	int mid;
	int ans = 1000;

	while (left <= right) {


		mid = (left + right) / 2;
		
		int cnt = 0; //���Ӱ� �߰��� (�ްԼ� ���� ��ġ�ɼ��ִ�) "�ްԼ� ����"

		for (int i = 1; i < (int)v1.size(); i++) { // v1[0]�� v1[n+1]�� 0�� L 
			int dist = v1[i] - v1[i - 1]; //v1[1]-v1[0]:ù��° ����

		
				cnt += (dist / mid);
				if (dist % mid == 0) { //�ްԼ� �̹� �ִ� ��ġ���
					cnt--;
				}
			
		}

		if (cnt > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			ans = min(mid,ans);
		}
		

	}
	cout << ans << endl;

	
	return 0;
}