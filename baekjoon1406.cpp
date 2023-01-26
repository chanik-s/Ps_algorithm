#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> L;
	int m;
	string s;
	
	cin >> s;
	cin >> m; //명령어 개수

	for (auto n : s) {
		L.push_back(n);
	}

	auto cursor = L.end();

	while (m--)
	{
		char op;
		cin >> op;

		if (op == 'P') {
			char add;
			cin >> add;
			L.insert(cursor, add);
		}
		else if (op == 'L') {
			if(cursor!=L.begin()) cursor--;
		}
		else if (op == 'D') {
			if(cursor!=L.end()) cursor++;
		}
		else { //'B'
			if (cursor != L.begin()) cursor=L.erase(--cursor);

		}
	}



	
	//출력
	for (auto i : L)
	{
		cout << i;
	}
	return 0;
}
