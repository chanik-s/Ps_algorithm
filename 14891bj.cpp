#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string board[4];//��Ϲ��� �ε��� 0~3 , 4��
void f(int x,int dir) { //ȸ�� ó��  x=��Ϲ��� �ε��� , dir=����

	int dirs[4] = {0,};//�� ��Ϲ������� �ʱ� ����
	dirs[x] = dir; //��Ϲ��� x�� ���� ����

	int idx = x;//��Ϲ��� �ε��� �޾ƿ� 0,1,2,3 �� �ϳ�
	//���� ����(�ε����� 1,2,3�϶�)
	//[idx][6]=>�ش� ��Ϲ��� 9�� ���� [idx-1][2]=>���� �� ��Ϲ��� 3�ù���
	while (idx > 0 && board[idx][6] != board[idx - 1][2]) {//������ ��ȸ��
		
		dirs[idx - 1] = -dirs[idx];//���� �� ����ݴ��
		idx--;                     //�� �� ������ �ϳ� �� �ݺ�
	}

	//������ ����(�ε����� 0,1,2�϶�)
	while(idx<3&&board[idx][2]!=board[idx+1][6])
	{
		dirs[idx + 1] = -dirs[idx];//������ �� ���� �ݴ��
		idx++;
	}
	for (int i = 0; i < 4; i++) {//�� ��Ϲ������� (dirs���� ����)ȸ��

		if (dirs[i] == -1) { //�ݽð�
			rotate(board[i].begin(), board[i].begin() + 1, board[i].end());
			//�Լ��� ��� ���(middle)�� ù ��ҷ� �ٲ� 
			// ex> v.begin() + 1 ���� 1ĭ�̵�
			//������ ȸ����Ű�� �� ������ Ƚ����ŭ ���������� ȸ����Ű�ų�, �������� ȸ���� �� �ִ�.
		}
		else if(dirs[i]==1) //�ð�
		{
			rotate(board[i].begin(), board[i].begin() + 7, board[i].end());
			// ex> v.begin() + 7 ���� 7ĭ�̵� 
			// ex> v.end()-1 ������ 1ĭ�̵�
		}
		//dirs[i]==0�̸� ��ȸ��,,�״��
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++)
		cin >> board[i]; //��Ϲ��� �������� ���ڿ� ������ '10010101'

	int k;
	cin >> k; //ȸ�� Ƚ��
	
	for (int i = 0; i < k; i++) {

		int num, dir; //dir: 1 �ð� -1 �ݽð�

		cin >> num >> dir; //3 -1 �ϰ�� 3�� ��Ϲ���(3) �ݽð�(-1) �̵�

		f(num-1,dir); //ȸ��..4�� ��ϴ� �ε����� 3�̹Ƿ� num-1
	}//ȸ�� ��

	//��� ���� ���
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (board[i][0] == '0') //n���̸� 0
		{
			ans += 0;
		}
	}
		if (board[0][0] == '1') {
			ans += 1 ;
		}
		if (board[1][0] == '1') {
			ans += 2;
		}
		if (board[2][0] == '1') {
			ans += 4;
		}
		if (board[3][0] == '1') {
			ans += 8;
		}


	cout << ans;

	return 0;
}