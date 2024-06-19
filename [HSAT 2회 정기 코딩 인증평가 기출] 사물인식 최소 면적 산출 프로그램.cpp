#include<iostream>
#include <vector>
#include <utility>

using namespace std;
//          x     y    k
//int board[2002][2002][22];
//vector<int> points[22]; //K개의 점
vector<vector<pair<int, int>> > points;
//K개의 숫자를 인덱스로 사용하는 방식! 
// points[0]: k=1 색깔의 좌표들을 담은 배열
// points[1]: k=2 색깔의 좌표  ..
// points[K-1]까지 존재
int ans; //면적 --최대 2000 * 2000
int n, K;
void dfs(int cnt, int minX, int maxX, int minY, int maxY) {
    if (cnt == K) { //종료 조건
        int area = (maxX - minX) * (maxY - minY);
        if (ans > area) ans = area;
        return;
    }
    //cnt(색깔)값 0부터 K-1까지 탐색
    for (int i = 0; i < points[cnt].size(); i++) {
        int x = points[cnt][i].first; // {x,y} 중 x
        int y = points[cnt][i].second;// {x,y} 중 y
        int minX2 = minX;
        int maxX2 = maxX;
        int minY2 = minY;
        int maxY2 = maxY;
        if (minX > x) minX2 = x; //최솟값 구할때 1e9는 매우 큰값이므로 바로 배제
        if (maxX < x) maxX2 = x; //최댓값 구할때 -1e9는 매우 작은값이므로 배제
        if (minY > y) minY2 = y;
        if (maxY < y) maxY2 = y;
        //초기에는 minX2=maxX2 ,minY2=maxY2 같아서 area=0
        int area = (maxX2 - minX2) * (maxY2 - minY2);
        //ans 초깃값 :매우 큰 수 ==>무한대(1e9)
        //업데이트후 dfs() return 되어 돌아오는 경우 그당시 최솟값 ans로 저장
        //현재 구한 area값과 비교
        if (ans <= area) { //현재 구하는 값이 최솟값 구하는 것이므로!
            continue; //for문 인덱스 증가
        }
        dfs(cnt + 1, minX2, maxX2, minY2, maxY2);
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> K;
    points.resize(K);
    ans = 1e9;
    for (int i = 0; i < n; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        points[k - 1].push_back({ x,y });
    }
    dfs(0, 1e9, -1e9, 1e9, -1e9); //매우 큰 값으로 1e9 이용
    cout << ans << '\n';
    // for(auto a:v){
    //     cout<<a.first.first<<' '<<a.first.second<<' '<<a.second<<'\n';
    // }

    return 0;
}