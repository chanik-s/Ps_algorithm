#include <iostream>
using namespace std;

int board[130][130];
int n;
int cnt_white;
int cnt_blue;

bool check(int n,int x,int y) { //

	for(int i=x;i<x+n;i++)
		for (int j = y; j <y+n; j++)
		{
			//�����¿� �ϳ��� �ٸ��� false
			if (board[i][j]!=board[x][y]) return false;
		}
	return true;
}
void func(int n,int x,int y) { //x=0 y=0

	if (check(n,x,y)) {
		if (board[x][y] == 1) cnt_blue++;
		if (board[x][y] == 0) cnt_white++;
		return;
	}
	else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				func(n / 2, x + i * n / 2 , y + j * n / 2); //4������� �߶���
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j]; //�Ͼ� 0 �Ķ� 1

		}
	}
	//�˰���
	func(n,0,0); //������ x=0 y=0 ������

	//���
	cout << cnt_white << '\n' << cnt_blue;
	return 0;
}