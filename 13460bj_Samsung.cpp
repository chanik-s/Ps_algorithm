#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int m, n;
pair<int, int> red, blue;
string board[11];
//dist[a][b][c][d]: �������� (a,b)��ǥ , �Ķ����� (c,d)��ǥ�� �����ϱ� ���� ���� Ƚ��
int dist[11][11][11][11]; //�Ÿ� ���
//�� �Ʒ� �� ��
int dx[4] = { 0,1,0,-1 };
int dy[4] = {1,0,-1,0};

int bfs() {
	//�Ķ���� 3���̻��ϰ�� Ʃ�� �̿�
	queue<tuple<int, int, int, int> > q;
	q.push({ red.X,red.Y,blue.X,blue.Y }); //4�� ���� �ִ� Ʃ�� ���·� ����
	dist[red.X][red.Y][blue.X][blue.Y]=0;

	while (!q.empty()) {
		int rx, ry, bx, by; //���� ������ x,y ��ǥ
		tie(rx, ry, bx, by) = q.front();//front()�� ���� Ʃ�����·� return�Ǵµ� �̸� ������ �ް� ������
		                                //tie()�� �Ἥ �̹� ����� rx,ry,bx,by�� ������ �ϳ��� ��
		q.pop();
		int cnt = dist[rx][ry][bx][by]; //return�� ���
		//10���ȿ� ���ϸ� -1
		if (cnt >= 10)
			return -1;
		//4���� ����̱�
		for (int i = 0; i < 4; i++) { //�� ���⿡ ���� Red Blue �Բ� �̵�
			int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by; 
			//���������� �ٲ� ������ x,y��ǥ.. �ʱ�ȭ�� ���� ��ǥ

			//Blue �̵�
			   //�����¿�������ٵ� '.'�����߸� �̵�������

			//����̸� �� ���������� �޿��� �̵� �׷��� while��
			while (board[n_bx + dx[i]][n_by + dy[i]] == '.') { //#�� O ������ ������ �ݺ��ؼ� �̵�
				n_bx += dx[i]; //���������� ���� ��ġ
				n_by += dy[i];
			}
			//Blue Ż��� ����
			if (board[n_bx + dx[i]][n_by + dy[i]] == 'O') continue; //���д� �������(���� ���̽���)

			//Red �̵�
			while (board[n_rx + dx[i]][n_ry + dy[i]] == '.') {
				n_rx += dx[i];
				n_ry += dy[i];
			}
			//Red Ż��� ���� ���� ��ȯ
			if (board[n_rx + dx[i]][n_ry + dy[i]] == 'O') return cnt + 1;//�� +1?

			//���� ��,�� �󿡼� Red,blue ������->�ʰ� ����� ���� ��ĭ ��
			if ((n_rx == n_bx) && (n_ry == n_by)) {
				if (i == 0) { //������ 
					ry < by ? n_ry-- : n_by--;
				}
				else if (i == 1) { //�Ʒ�
					rx < bx ? n_rx-- : n_bx--;
				}
				else if (i == 2) { //��
					ry > by ? n_ry++ : n_by++;
				}
				else //��
					rx > bx ? n_rx++ : n_bx++;
			}

			//�̹� (n_rx, n_ry, n_bx , n_by) �湮������ ���
			if (dist[n_rx][n_ry][n_bx][n_by] != -1) continue;
			dist[n_rx][n_ry][n_bx][n_by] = cnt + 1; //�湮���� �ʾҴٸ�
			q.push({ n_rx, n_ry, n_bx , n_by });

		}


	}
	return -1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				fill(dist[i][j][k], dist[i][j][k] + 10, -1); //�̹湮: �Ÿ� -1�� �ʱ�ȭ
			}
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'B') {
				blue = { i,j };
				board[i][j] = '.';//?��      ��￩�� �ٽ� �� �� �ִ� ������ �����ؼ� ??
			}
			else if (board[i][j] == 'R') {
				red = { i,j }; //���� ���� ��ġ ��ǥ �����صΰ�
				board[i][j] = '.'; //�� �� �ִ� ĭ���� �ν��ϰ�
			}
		}

	}

	cout << bfs(); //4���� bfs������

	return 0;
}