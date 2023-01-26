#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	int sum = 0;
	stack<int> s;
	while (k--)
	{
		int n;
		cin >> n;

		if (!n) s.pop();
		else
			s.push(n);
	}
	
	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
	}
	
	cout << sum;
	return 0;
}