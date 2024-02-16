#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
int W[101];   //W[0]=0
int V[101];   //V[0]=0
int D[101][100001]; //D[0][]=0


int main() {

	cin >> n>> k;

	//vector<pair<int, int> > v1(n);//���� n��

	for (int i = 1; i <= n; i++) //1������ n�� ���� 
	{
		cin >> W[i] >> V[i];
	}

	//�ʱ갪
	for (int i = 0; i <= n; i++) {
		D[i][0] = 0;
	}
	for (int i = 0; i <= k; i++) {
		D[0][i] = 0;
	}

	//dp -->d[i][k]:1��°~i��° ���Ǳ��� ����� ������ �ִ� �ִ� ��ġ

	//limit �������� i=1~n���� d[i][limit] ����ϴ� �帧 
	for (int limit = 1; limit <= k; limit++) {
		for (int i = 1; i <= n; i++) { // i=1���� i=n���� d[i][k]

			if (W[i] > limit) { //������ ����
				D[i][limit] = D[i - 1][limit];
			}
			else {//�־�
				D[i][limit] = max(D[i-1][limit-W[i]]+V[i],D[i-1][limit]);
			}
		}
	}

	cout << D[n][k];
	return 0;
}