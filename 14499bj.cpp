#include <iostream>

using namespace std;
int n, m;
int board[22][22];//������ �� ĭ�� ������
int x, y,k;


int dice[7]; //�ε��� 1~6������ 0~5���..�״�� 0�ε����� �Ⱦ��°�=> dice[0]�� �ǹ̾���
// {0, 1,2,3,4,5,6}  2�� ���� 6�� ���� 4�� �ٴ�
//      [1]
//  [5] [2] [6]
//      [3]
//      [4]

int idx[5][4] = {
	{}, //dummy.. ���� ����
	{2,6,4,5}, //��(dir=1)
	{2,5,4,6}, //��
	{3,2,1,4}, //��
	{2,3,4,1} //��
};

void roll(int dir) {//dir=1~4��
	//ȸ���� ���� �ֻ��� �� �����ϱ����� �迭
	int tmp[7]; //�ε��� 1~6 ����ҷ��� 0~5���.. tmp[0]�� ���õ�
	 
	for (int i = 1; i <= 6; i++) tmp[i] = dice[i]; //�ֻ��� �� 6�� ����

	//����--4���� ����..������ ���� 2���� ������ (�ֻ������� 2���� �������)
	for (int i = 0; i < 4; i++) {
		tmp[idx[dir][(i + 1) % 4]] = dice[idx[dir][i]]; //idx[][0~3�� �����̹Ƿ� ���������]
	}

	for (int i = 1; i <= 6; i++) dice[i] = tmp[i];

}
bool check(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	else
		return true;
}

void move(int dir) { //�������� �� �ϳ� ��� �޾ƿͼ� �̵�
	//���ÿ����� �������� ��ĭ �̵��� ������
	int nx = x, ny = y;
	//�ϴ� �̵��ϰ�
	if (dir == 4) //����
	{
		nx = nx + 1;
	} //�ֻ��� ��ġ����
	else if (dir == 3) //����
	{
		nx = nx - 1;
	}
	else if (dir == 2) //��
		{ny = ny -1;}
	else if (dir == 1) //�� 
		{ny = ny +1;}
	
	if (check(nx, ny)) {//���� ������ʾƾ�
		x = nx; y = ny; //�ֻ��� ��ġ �ٲ���ƾ���

		roll(dir);

		//�̵��� ĭ�� ���� ���� �з�
		if (board[nx][ny] == 0) {

			board[nx][ny] = dice[4];
		}
		else {
			dice[4] = board[nx][ny];//ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����
			board[nx][ny] = 0;
		}

		cout<<dice[2]<<endl; //����	
	}
	//����� ��� x

	
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//�Է�
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; //NxM ������ �����ִ� ��
			//�ֻ����� ���� ĭ�� ���� �ִ� ���� �׻� 0 -->���ÿ����� (0,0) ��ǥ�� ���� 0
		}
	}
	for (int i = 0; i < k; i++) { //k���� ���
		int dir;
		cin >> dir; //���� 1 ���� 2 ���� 3 ����  4
		//�˰���
		move(dir);
	}
	

	//���

	return 0;
}