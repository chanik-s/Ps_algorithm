#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> v1;

	//각 원소 뒤집기
	for (int i = 0; i < n; i++) {

		string s;
		cin >> s; //"2233"
		reverse(s.begin(),s.end());	//역순
		// algorithm 헤더 reverse() 존재-->"3322"
		v1.push_back( stoll(s));
	}

	//문자열 비교시 맨 앞 기준으로 비교  예를 들어 "123" < "5" 가 됨
	
	
	//원소 오름차순 정렬 
	sort(v1.begin(), v1.end()); 

	for (auto s : v1) {
		cout << s << '\n';
	}
	return 0;
}
