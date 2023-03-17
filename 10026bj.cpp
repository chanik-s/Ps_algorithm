#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;
string board[102];
bool vis[102][102];
bool vis2[102][102];
int n;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<int,int> > q1;
queue <pair<int,int> > q2;
int cnt1;
int cnt2;

int main() {

	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> board[i];//RRRBB
		//R�� G�� ���������� �ν�
	}
	//����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 1) continue;
			//�湮 ��������
			cnt1++;
			vis[i][j] = 1;
			//�� �����ְ�
			char color = board[i][j]; //R
			q1.push({ i,j });

			while (!q1.empty()) {
			
				auto cur = q1.front(); q1.pop();
				for (int dir = 0; dir < 4; dir++) {

					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny]||board[nx][ny]!=color) continue;
					vis[nx][ny] = 1; //�湮ó��
					q1.push({ nx,ny });
				}

			}
		}
	}

	
	//���ϻ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis2[i][j] == 1) continue;
			cnt2++;
			//�湮 ��������
			vis2[i][j] = 1;
			//�� �����ְ�
			//char color2 = board[i][j]; //R
			q2.push({ i,j });
			
			while (!q2.empty()) {
				
				auto cur = q2.front(); q2.pop();
				for (int dir = 0; dir < 4; dir++) {

					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis2[nx][ny]) continue;
					
					if (board[i][j] == 'R') {
						if (board[nx][ny] == 'G'||board[nx][ny]=='R') {
							vis2[nx][ny] = 1;
							q2.push({ nx,ny });
						}
						else {
							
						}
					}
					else if (board[i][j] == 'G') {

						if (board[nx][ny] == 'G' || board[nx][ny] == 'R') {
							vis2[nx][ny] = 1;
							q2.push({ nx,ny });
						}
						else {

						}
					}
					else { //'B'
						if (board[nx][ny] == board[i][j]) {
							vis2[nx][ny] = 1;
							q2.push({ nx,ny });
						}

					}


				}


			}
		}
	}
	

	cout << cnt1 << ' ' << cnt2;

	return 0;
}