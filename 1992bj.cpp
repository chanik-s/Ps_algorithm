#include <iostream>
#include <string>
using namespace std;
int board[66][66];
int n;
bool check(int n,int x,int y) {

	for (int i = x; i < x+n; i++) {
		for (int j = y; j <y+n; j++) {
			if (board[i][j] != board[x][y])
				return false;
		}
	}
	return true;
}
void func(int n, int x, int y) {
	if (n == 1) {
		cout << board[x][y];
		return;
	}
	if (check(n,x,y)) {
		if (board[x][y] == 1)
			cout << 1;
		if(board[x][y]==0) //board[]==0
			cout<< 0;
	}
	else {
		cout << "(";
		for(int i=0;i<2;i++) //4등분
			for(int j=0;j<2;j++)
				func(n / 2, x+i*n/2, y+j*n/2);
		cout << ")";
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s; //문자열로 입력받아야함 (여기서 헛고생)
		cin >> s;
		for (int j = 0; j < n; j++) {
			board[i][j] = s[j] - '0'; //숫자로 변환
		}
	}
	/*
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	*/
	func(n, 0, 0);
	return 0;
}