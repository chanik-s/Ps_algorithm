#include <bits/stdc++.h>

using namespace std;

int N;
int A[505][505];
//�� x�״�� y���� (������)
//�� x�״�� y���� (����)
//�� x���� y �״�� (�Ʒ�)
//�� x���� y �״�� (��)
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer;  //���ڹ����� �̵� �𷡾�

//4=>�� �� �� �� ������ ����
//���� ���� :  {1,1,7,7,10,10,2,2,5,a} ������ 10�� ����
//[0]:���� [1]:���� [2]:���� [3]: ����
int  xdx[4][10] = { {-1,1,-1,1,-1,1,-2,2,0,0},{-1,1,-1,1,-1,1,-2,2,0,0},
	{0,0,1,1,2,2,1,1,3,2},{0,0,-1,-1,-2,-2,-1,-1,-3,-2} };
int ydy[4][10] = { {0,0,1,1,2,2,1,1,3,2},{0,0,-1,-1,-2,-2,-1,-1,-3,-2},
	{-1,1,-1,1,-1,1,-2,2,0,0},{-1,1,-1,1,-1,1,-2,2,0,0} };
int percent[9] = { 1,1,7,7,10,10,2,2,5 }; //����

int change_dir(int Dir) {       //->
	if (Dir == 0) return 3; //��     ��
	if (Dir == 1) return 2; //��     ��
	if (Dir == 2) return 0; //��     ��
	if (Dir == 3) return 1; //��     ��
}

void Spread_Sand(int x,int y,int Dir) { //Dir=>��������
	int xx = x + dx[Dir];
	int yy = y + dy[Dir];
	if (A[xx][yy] == 0) return; //�̵��� ��(�������� y)�� �𷡾��� 0�̸� ���� �����൵ 0
	
	int Sand = A[xx][yy]; //�𷡾�
	int Tmp = Sand;
	for (int i = 0; i < 9; i++) { //�������Ͽ� ���� �ٸ� ��ǥ Ž��   9���� ����.. ����a�� ���Ѱ� ����
		int nx = x+xdx[Dir][i];
		int ny = y+ydy[Dir][i];
		int Per = percent[i];
		int Plus = (Tmp * Per) / 100;

		if (nx < 1 || ny < 1 || nx > N || ny > N) 
			answer += Plus;
		else
			A[nx][ny] += Plus;

		Sand -= Plus; //���� ������ ���� ���� �� �� (������ ������ Plus��簪 ���ָ� ������)
	}
	//������ ��ǥ a���Ŀ� ���� ��
	int nx = x + xdx[Dir][9];
	int ny = y + ydy[Dir][9];

	if (nx < 1 || ny < 1 || nx > N || ny > N) answer += Sand; //���ڹ����� �̵� �𷡾�
	else A[nx][ny] += Sand; //�𷡰� �̹� �ִ� ĭ���� �𷡰� �̵��ϸ�, ���� ���� ��������. 
	
	A[xx][yy] = 0; //��??
}
void Solution() {
	int Dir = 1; //���� ���� ù��°��!
	int move_cnt=1;
	//���� (N/2 + 1 , N/2 + 1)
	int x = (N / 2) + 1;
	int y = (N / 2) + 1;

	while (1) {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < move_cnt; j++) {  //����̵��� �������� �ϴ� ĭ���� move_cnt
				Spread_Sand(x, y, Dir); //����(Dir=1)���� ����
				//��ǥ �̵�  (ó���� ��������)
				x += dx[Dir];
				y += dy[Dir];
			}
			Dir = change_dir(Dir); // ��->��->��->�� ��� �� �ϸ��� ���� �ٲٰ�

		} //2�� �ݺ�

		move_cnt++; // 1ĭ 2�� 2ĭ 2�� ...  6ĭ 2�� ...
 		if (move_cnt == N) { //7ĭ�϶�
			
			for (int j = 0; j < move_cnt; j++) {  //����̵��� �������� �ϴ� ĭ���� move_cnt
				Spread_Sand(x, y, Dir); 
				//��ǥ �̵� 
				x += dx[Dir];
				y += dy[Dir];
			}
			break;
		}

	}
	cout << answer << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; //Ȧ�� ex>7
	for (int i = 1; i <= N; i++) {   //1~N����
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j]; // �� ��
		}
	}
	
	Solution();

	return 0;
}