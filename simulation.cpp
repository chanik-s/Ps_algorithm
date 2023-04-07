#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int board2[10][10]; //cctv ���ÿ����� �ɸ��� ��ĭ�� ���� 7�� ����
int n, m;
//int k = 0; //cctv �� �ִ� 8
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector <pair<int, int>> cctv; //cctv ��ǥ

bool OOB(int a, int b) { //���� üũ
	return a < 0 || a >= n || b < 0 || b >= m; //����� true ��ȯ
}

void upd(int x, int y, int dir) { //���ÿ��� 7������ üũ���ִ�
	dir %= 4;
	while (1) {
		//dir(ex>dir=0,����)�� �������� �� �������� �޿� ����?
		x += dx[dir]; 
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return; //���� ����ų� ���̸� ����
		if (board2[x][y] != 0) continue; //�ش�ĭ cctv������ �Ѿ��
		board2[x][y] = 7; //���ÿ��� ���Ե��� �ǹ�
	}
}
int main() {  
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>> n >> m; //���� ����
	int mn = 0; //�簢 ���� �ּ� ũ��(��)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; // 0��ĭ   1~5 cctv     6��
		
			if (board[i][j] != 0 && board[i][j] != 6)
				cctv.push_back({ i,j }); //cctv vector�� ����
			if (board[i][j] == 0) mn++; //�ʱ⿣ ��ĭ ���� ��
		}
	}
	
	//pow(4,k)���� pow�� ������ ������ �ϸ� ���� ���������� 
	//cctv.size() : ���Ϳ� �� cctv����(k��)
	//1<<2*cctv.size--> 2^(2*k) ==> 4^k       

	for (int tmp = 0; tmp < 1<<(2*cctv.size()); tmp++) { //cctv 3���϶� 64���� (0~4^3-1)
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board[i][j]; //board�� �ִ� �� �ϴ� ����..board2[][]���� 7 �־� ���� ���� ǥ��
			}
		}
		int brute = tmp;//  �ӽ� ������ �ּ� tmp ���� �Űܴ��� �� brute�� 4�� ���������� ���
		
		for (int i = 0; i < cctv.size(); i++) { //3�� ==>k

			int dir = brute % 4;       //4���� ���� ������������ ����(0,1,2,3) ���� 
			brute /= 4;

			int x = cctv[i].first;
			int y = cctv[i].second;
			if (board[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (board[x][y] == 2) {
				upd(x, y, dir);
				upd(x, y, dir + 2);
				//2���� ����
				//(0,2):(�Ʒ�,��)     (1,3):(����,��)  (2,4%4):(��,�Ʒ�)   (3,5%4):(��,��)
			}
			else if (board[x][y] == 3) {
				upd(x, y, dir);
				upd(x, y, dir + 1); //����
			}
			else if (board[x][y] == 4) {
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
			}
			else //board[][]==5
			{
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
		} //��� cctv�����ؼ� ���ÿ��� ǥ�� ������

			int sum = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					sum += (board2[i][j] == 0); //()������ ���̸� +1 :���ÿ��� ���ذ� �簢����
				}
			}
			mn = min(mn, sum);	
	}
	cout << mn;

	return 0;
}