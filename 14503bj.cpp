#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int n, m,d; // d:����  d=0 �� 1 �� 2 �� 3 ��
int board[55][55]; // [n] [m]
int cnt; //û���ϴ� ĭ ����
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//�� �� �� ��

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	int r, c; //�ʱ� �κ� ��ġ
	cin >> r >> c >> d; //�ε��� ��� �ʿ����

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {

		if (board[r][c]==0) { //���� ĭ û�ҵ��� ���� ��ĭ(0)   <--> �� (1) 
			cnt++; //û�� Ƚ�� ����
		}
		board[r][c] = -1;//û�ҵ��� ��� -1 
		
		bool cleaned = false; //�� ������ û�ҵ� �� �ִ���

		for (int dir = 0; dir < 4; dir++) { //�ֺ� 4���� �ݺ�
		
			//�ݽð� 90 ȸ��
			if (d == 0) d = 3;
			else if (d == 1) d = 0;
			else if (d == 2) d = 1;
			else d = 2;
			////���� ĭ û�ҵ��� ���� ��ĭ�̸� ����
			if (board[r + dx[d]][c + dy[d]] == 0) {
				//����
				r = r + dx[d];
				c = c + dy[d];

				//1�� ���ư�
				cleaned = true; 
				break;
			}
		}
		
		if (cleaned) continue; //1������ ���ư��� ����
		//continue������ �Ʒ� �ڵ� ���������ʰ� ���� while������ ����

		// �� ������ û�ҵ��� ���� ��ĭ ���� ���==> ��, for������ �ƹ��͵� ���Ѱ�
		// ��� û�ҵ� board[][]==-1
		if (board[r - dx[d]][c - dy[d]] == 1) //��
			break; //�۵� �� while�� ��
		else {
			//����		
			r = r - dx[d];
			c = c - dy[d];
		}
	}
	


	cout << cnt;

	return 0;
}