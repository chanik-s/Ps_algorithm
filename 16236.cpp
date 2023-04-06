#include <bits/stdc++.h>
using namespace std;

int n, m;
// fish[25][25];//물고기 크기 멥
int space[25][25];//상태 맵 ---> 물고기 크기담는 배열로 변경
int s_baby=2; //아기상어크기
int eatfish = 0; //얼마만큼의 물고기 먹었는지 양
int sec;
int dist[25][25]; //거리(시간)
int dx[4] = { 1,0,-1,0 };  //아래  오른 위쪽 왼쪽
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> baby_pos; //아기 상어 위치 담을 큐
int shark_x;
int shark_y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cin >> space[i][j]; 

			if (space[i][j] == 9) {
				shark_x = i;
				shark_y = j;
			}
		}
	}

	while (1) { //1마리에 대한 과정 반복

		for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);//거리 -1로 초기화

		space[shark_x][shark_y] = 0; //물고기 없으므로 0(아기 상어 위치)  9이면 물고기크기로 인식해 지나가지못해 
		dist[shark_x][shark_y] = 0;//시작했으니 거리 0으로 초기화  
		
		vector<pair<int, int> > fish; //상어가 먹을수있는 물고기 좌표 넣어준 벡터(배열)
		
		if (eatfish >= s_baby) {
			eatfish = eatfish - s_baby; //다시 0으로
			s_baby++;
		}
		
		
		baby_pos.push({ shark_x,shark_y });//아기 상어 좌표 위치

		while (!baby_pos.empty()) { //아기상어 초기위치로부터 탐색 완료시

			auto cur = baby_pos.front(); //좌표 세트 저장
			baby_pos.pop();

			for (int dir = 0; dir < 4; dir++) { //아래 오른 위 왼
				int nx = cur.first + dx[dir]; //아기상어 다음위치
				int ny = cur.second + dy[dir];
				// 자신의 크기보다 작은 물고기만 먹을 수 있다.
				// 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue; //범위 벗어나
				if (dist[nx][ny] != -1) continue; //방문처리된 건 넘어가
				
				if (space[nx][ny] > s_baby) continue; //물고기 크기가 더크면 못가
				else if (space[nx][ny] == s_baby||space[nx][ny]==0) { //같거나 빈칸 이동 가능
					baby_pos.push({ nx,ny });
					//먹지는 않고 지나가기만 함 
					dist[nx][ny] = dist[cur.first][cur.second] + 1;//거리 증가
				}
				//아기 상어보다 작으면
				else if (space[nx][ny] < s_baby&&space[nx][ny]>=1) { //1보다 크면 먹을수 있다는 것
					fish.push_back({ nx,ny }); 
					dist[nx][ny] = dist[cur.first][cur.second] + 1;//거리 증가
				}



				//baby_pos.push({nx,ny});
			}
		} //아기 상어 위치로부터 모든 위치 탐색(BFS)--> fish 배열에 먹을수 있는 물고기 위치 저장

		if (fish.size() == 0) { //먹을수 없음     bfs과정에서 물고기 좌표 배열에 pushback 한번도 안함
			cout << sec << '\n';
			return 0; //종료
		}
		else if (fish.size() == 1) { //한마리
			
			//그 위치로 이동
			shark_x = fish[0].first; //첫번째 원소에만 저장
			shark_y = fish[0].second;

			//먹었으니 빈칸
			space[shark_x][shark_y] = 0;
			eatfish++; //나중에, eatfish가 자기 크기랑 같은 수 되면  +1
			sec += dist[shark_x][shark_y]; //그 지점까지의 거리값(초기 상어 위치=0 기준)
		}
		else { //2마리 이상
			int mindlist = 1e5; 

			for (auto& x : fish) {
				mindlist = min(mindlist, dist[x.first][x.second]);
			}

			int mincnt = 0;
			vector<pair<int, int>> minfish; //가장 가까운 물고기 좌표 담을 그릇

			//&는..  vector<pair<int, int> > fish... 에서 배열 요소 참조 (복사본x)
			for (auto& x : fish) {//fish배열에 들어있는 원소x(0~(size-1))에 대해서 
				if (mindlist == dist[x.first][x.second]) {
					minfish.push_back({x.first,x.second}); //지나야하는 거리값의 최솟값
				}
			}
			if (minfish.size() == 1) {
				shark_x = minfish[0].first;//거리가 가장 가까운 1마리의 좌표
				shark_y = minfish[0].second;
				sec += dist[shark_x][shark_y];
				space[shark_x][shark_y] = 0; //먹었으니 그 칸 0으로
				eatfish++; //1마리 먹었으니 증가
			}
			else { //거리가 가까운 물고기가 많을때 가장 위(1행쪽) +  가장 왼쪽(1열쪽) 우선시
				sort(minfish.begin(), minfish.end()); //2차원 벡터를 정렬해본다. 기본적으로는 사전순으로 정렬
				shark_x = minfish[0].first;//거리가 가장 가까운 1마리의 좌표
				shark_y = minfish[0].second;
				sec += dist[shark_x][shark_y];
				space[shark_x][shark_y] = 0; //먹었으니 그 칸 0으로
				eatfish++; //1마리 먹었으니 증가
			}


		}
	}
	



	return 0;
}