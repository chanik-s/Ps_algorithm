#include <iostream>

using namespace std;
char map[25][25];
int R, C;
 
int bag[26];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int answer=0;
void DFS(int x, int y,int cnt) {
	
	bag[map[x][y] - 'A'] = 1;
	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = x + dx[i]; //�� ����
		yy = y + dy[i]; //�� ����

		if ((xx >= 0 && xx <R) && (yy >=0 && yy < C) && (!bag[map[xx][yy] - 'A']))  // bag�� 0�̸� -->�湮��������
		{
			DFS(xx, yy, cnt + 1);
		}

	}
	bag[map[x][y] - 'A'] = 0;
	if (answer < cnt) answer = cnt;
}
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int T;
	cin >> T; //TC ->> t=3�̸� �� ���� ���� �����������

	for (int t = 0; t < T; ++t) {

		cin >> R >> C; //R >=1 C<=20

		for (int j = 0; j < R; j++) {
			string str;
			cin >> str;

			for (int i = 0; i < C; i++)
			{
				map[j][i] = str[i];
			}
		}

		DFS(0,0,1);
		cout << "#" << t + 1 << " " << answer << "\n"; //�ִ� index?
		answer = 0; //���������� ���� 
	}
	return 0;
}