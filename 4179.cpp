#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;

string maze[1002];
//bool vis[1002][1002]; //0�Ǵ� 1
int dist1[1002][1002]; //�� ���Ľð� 
int dist2[1002][1002]; //������ �̵��ð�
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	queue <pair <int, int> > q1; //��
	queue <pair <int, int> > q2; //����

	//�Է�
	for (int i = 0; i < r; i++)
	{
		fill(dist1[i], dist1[i] + c, -1);
		fill(dist2[i], dist2[i] + c, -1);
	}
	for (int j = 0; j < r; j++)
	{
		cin>> maze[j];
	}
		

	for (int j = 0; j <r; j++) {
		for(int i=0;i<c;i++){
			if (maze[j][i] == 'J') //J�� �ϳ���
			{
	                            
				q2.push({ j,i }); //������ ť �ֱ�
				dist2[j][i] = 0;
			}
			if (maze[j][i] == 'F') {
				q1.push({ j,i }); //������ ť �ֱ�
				dist1[j][i] = 0; //����->>0����
			}
		}
		
	}

	//�˰��� ��
	while (!q1.empty()) {

		auto cur = q1.front(); q1.pop(); //���� ���, cur={1,2}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir]; //first=1
			int ny = cur.second + dy[dir];//second=2
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (dist1[nx][ny] >= 0 || maze[nx][ny] == '#') continue;

			dist1[nx][ny] = dist1[cur.first][cur.second] + 1; //ó�� 'F'�� 0(����)�̹Ƿ� ��ĭ�̵��� 1
			q1.push({ nx,ny });
		}
	}
	//����
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir]; //first=1
			int ny = cur.second + dy[dir];//second=2
			
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				//���� ��� ==> �ܰ� Ż��
				cout << dist2[cur.first][cur.second] + 1; //cur={3,1} dist2[][]=2 ���� 3
				return 0;
			}
			if (dist2[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
			//���� �ȵǰ�(!=-1)    ���� �Ȱ��ų� ������ �����ϸ� �ȵ� 

			dist2[nx][ny] = dist2[cur.first][cur.second] + 1; //ó�� 'F'�� 0(����)�̹Ƿ� ��ĭ�̵��� 1
			q2.push({ nx,ny });
		}
		
	}
	cout << "IMPOSSIBLE";

	return 0;
}