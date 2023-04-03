#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
//�丶��
//���� �� ���������� ��� ���������� �Ÿ� ���ϱ�
using namespace std;

int m, n;
int box[1002][1002]; //0�ʱ�ȭ
int dist[1002][1002];//0�ʱ�ȭ
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	queue <pair <int, int> > q;
	

	//box �� ��ǥ�� ���Ұ��� �Է� �ް� �� ��ǥ�� dist�迭 �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) q.push({ i,j }); //���� �丶��  ..������ bfs����(��� ������ ť�� �ֱ�)
			if (box[i][j] == 0) dist[i][j] = -1; //���� ���� �丶�� ..dist�迭�� -1�� �ʱ�ȭ
			//����,��ĭ -> dist�� �ڵ����� 0 
		}
	}
	//bfs����
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		//auto ->> pair<int,int> �ڵ�����
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first+dx[dir];
			int ny = cur.second+dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny>=m) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1; 
			//�ʱ� ��ġ������ �Ÿ��� �湮ó�� �ѹ��� ��Ÿ�� �� ����.. dist�迭
			q.push({ nx,ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) { //�丶�� ��� ���� ���ϴ� ��� 
				cout << -1;  
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
	return 0;
}