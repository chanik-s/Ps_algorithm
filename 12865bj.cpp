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

	//vector<pair<int, int> > v1(n);//물건 n개

	for (int i = 1; i <= n; i++) //1번부터 n번 물건 
	{
		cin >> W[i] >> V[i];
	}

	//초깃값
	for (int i = 0; i <= n; i++) {
		D[i][0] = 0;
	}
	for (int i = 0; i <= k; i++) {
		D[0][i] = 0;
	}

	//dp -->d[i][k]:1번째~i번째 물건까지 고려서 담을수 있는 최대 가치

	//limit 기준으로 i=1~n까지 d[i][limit] 계산하는 흐름 
	for (int limit = 1; limit <= k; limit++) {
		for (int i = 1; i <= n; i++) { // i=1부터 i=n까지 d[i][k]

			if (W[i] > limit) { //담을수 없어
				D[i][limit] = D[i - 1][limit];
			}
			else {//있어
				D[i][limit] = max(D[i-1][limit-W[i]]+V[i],D[i-1][limit]);
			}
		}
	}

	cout << D[n][k];
	return 0;
}