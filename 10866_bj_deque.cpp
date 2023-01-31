#include <iostream>
#include <string>
#include <deque>

using namespace std;
int main()
{
	int n;
	cin >> n;
	//int dat[10005] = {0};
	//int head, tail = 5000;
	deque<int> dq;
	while (n--) {

		string op;
		cin >> op;
		if (op == "push_back") {
			int x;
			cin >> x;
			//dat[tail++] = x;
			dq.push_back(x);
		}
		else if (op == "push_front") {
			int x;
			cin >> x;
			//dat[--head] = x;
			dq.push_front(x);
		}
		else if (op == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front()<<'\n';
				dq.pop_front();
			}
			else  cout << -1<<'\n';
		}
		else if (op == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else cout << -1<<'\n';
		}
		else if (op == "size") {
			cout << dq.size() << '\n';
		}
		else if (op == "empty") {
			if (!dq.empty()) {
				cout << 0 << '\n';
			}
			else cout << 1 << "\n";
		}
		else if (op == "front") {
			
			if (!dq.empty()) {
				cout << dq.front() << '\n';
			}
			else cout << -1 << "\n";
		}
		else {  //back
			if (!dq.empty()) {
				cout << dq.back()<< '\n';
			}
			else cout << -1 << "\n";
		}


	}

	return 0;
}