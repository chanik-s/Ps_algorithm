#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(char v1,char v2) {
	
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<string> v1;
	
	while (n--) {
		string k;
		cin >> k;
		v1.push_back(k);
	}

	for (int i = 0; i < v1.size(); i++) {

		//sort(v1[i].begin(), v1[i].end(),cmp );
		string tmp = "";
		for (string::reverse_iterator it = v1[i].rbegin(); it != v1[i].rend();it++) {
			tmp[i]=
		}
	}


	for (auto i : v1) {
		cout << i << ' ';
	}

	return 0;
}
