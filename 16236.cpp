#include <bits/stdc++.h>
using namespace std;

int n, m;
// fish[25][25];//����� ũ�� ��
int space[25][25];//���� �� ---> ����� ũ���� �迭�� ����
int s_baby=2; //�Ʊ���ũ��
int eatfish = 0; //�󸶸�ŭ�� ����� �Ծ����� ��
int sec;
int dist[25][25]; //�Ÿ�(�ð�)
int dx[4] = { 1,0,-1,0 };  //�Ʒ�  ���� ���� ����
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> baby_pos; //�Ʊ� ��� ��ġ ���� ť
int shark_x;
int shark_y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	//�Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cin >> space[i][j]; 

			if (space[i][j] == 9) {
				shark_x = i;
				shark_y = j;
			}
		}
	}

	while (1) { //1������ ���� ���� �ݺ�

		for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);//�Ÿ� -1�� �ʱ�ȭ

		space[shark_x][shark_y] = 0; //����� �����Ƿ� 0(�Ʊ� ��� ��ġ)  9�̸� �����ũ��� �ν��� ������������ 
		dist[shark_x][shark_y] = 0;//���������� �Ÿ� 0���� �ʱ�ȭ  
		
		vector<pair<int, int> > fish; //�� �������ִ� ����� ��ǥ �־��� ����(�迭)
		
		if (eatfish >= s_baby) {
			eatfish = eatfish - s_baby; //�ٽ� 0����
			s_baby++;
		}
		
		
		baby_pos.push({ shark_x,shark_y });//�Ʊ� ��� ��ǥ ��ġ

		while (!baby_pos.empty()) { //�Ʊ��� �ʱ���ġ�κ��� Ž�� �Ϸ��

			auto cur = baby_pos.front(); //��ǥ ��Ʈ ����
			baby_pos.pop();

			for (int dir = 0; dir < 4; dir++) { //�Ʒ� ���� �� ��
				int nx = cur.first + dx[dir]; //�Ʊ��� ������ġ
				int ny = cur.second + dy[dir];
				// �ڽ��� ũ�⺸�� ���� ����⸸ ���� �� �ִ�.
				// ũ�Ⱑ ���� ������ ���� �� ������, �� ����Ⱑ �ִ� ĭ�� ������ �� �ִ�.
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue; //���� ���
				if (dist[nx][ny] != -1) continue; //�湮ó���� �� �Ѿ
				
				if (space[nx][ny] > s_baby) continue; //����� ũ�Ⱑ ��ũ�� ����
				else if (space[nx][ny] == s_baby||space[nx][ny]==0) { //���ų� ��ĭ �̵� ����
					baby_pos.push({ nx,ny });
					//������ �ʰ� �������⸸ �� 
					dist[nx][ny] = dist[cur.first][cur.second] + 1;//�Ÿ� ����
				}
				//�Ʊ� ���� ������
				else if (space[nx][ny] < s_baby&&space[nx][ny]>=1) { //1���� ũ�� ������ �ִٴ� ��
					fish.push_back({ nx,ny }); 
					dist[nx][ny] = dist[cur.first][cur.second] + 1;//�Ÿ� ����
				}



				//baby_pos.push({nx,ny});
			}
		} //�Ʊ� ��� ��ġ�κ��� ��� ��ġ Ž��(BFS)--> fish �迭�� ������ �ִ� ����� ��ġ ����

		if (fish.size() == 0) { //������ ����     bfs�������� ����� ��ǥ �迭�� pushback �ѹ��� ����
			cout << sec << '\n';
			return 0; //����
		}
		else if (fish.size() == 1) { //�Ѹ���
			
			//�� ��ġ�� �̵�
			shark_x = fish[0].first; //ù��° ���ҿ��� ����
			shark_y = fish[0].second;

			//�Ծ����� ��ĭ
			space[shark_x][shark_y] = 0;
			eatfish++; //���߿�, eatfish�� �ڱ� ũ��� ���� �� �Ǹ�  +1
			sec += dist[shark_x][shark_y]; //�� ���������� �Ÿ���(�ʱ� ��� ��ġ=0 ����)
		}
		else { //2���� �̻�
			int mindlist = 1e5; 

			for (auto& x : fish) {
				mindlist = min(mindlist, dist[x.first][x.second]);
			}

			int mincnt = 0;
			vector<pair<int, int>> minfish; //���� ����� ����� ��ǥ ���� �׸�

			//&��..  vector<pair<int, int> > fish... ���� �迭 ��� ���� (���纻x)
			for (auto& x : fish) {//fish�迭�� ����ִ� ����x(0~(size-1))�� ���ؼ� 
				if (mindlist == dist[x.first][x.second]) {
					minfish.push_back({x.first,x.second}); //�������ϴ� �Ÿ����� �ּڰ�
				}
			}
			if (minfish.size() == 1) {
				shark_x = minfish[0].first;//�Ÿ��� ���� ����� 1������ ��ǥ
				shark_y = minfish[0].second;
				sec += dist[shark_x][shark_y];
				space[shark_x][shark_y] = 0; //�Ծ����� �� ĭ 0����
				eatfish++; //1���� �Ծ����� ����
			}
			else { //�Ÿ��� ����� ����Ⱑ ������ ���� ��(1����) +  ���� ����(1����) �켱��
				sort(minfish.begin(), minfish.end()); //2���� ���͸� �����غ���. �⺻�����δ� ���������� ����
				shark_x = minfish[0].first;//�Ÿ��� ���� ����� 1������ ��ǥ
				shark_y = minfish[0].second;
				sec += dist[shark_x][shark_y];
				space[shark_x][shark_y] = 0; //�Ծ����� �� ĭ 0����
				eatfish++; //1���� �Ծ����� ����
			}


		}
	}
	



	return 0;
}