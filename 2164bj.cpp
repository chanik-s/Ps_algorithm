#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	queue <int> q;

	for (int i = 1; i <= n; i++) { q.push(i); }

	while (q.size()>1) {

		q.pop(); //1 버려
		q.push(q.front()); //2 뒤에 넣어
		q.pop();
	}
	cout << q.front();


	return 0;
}