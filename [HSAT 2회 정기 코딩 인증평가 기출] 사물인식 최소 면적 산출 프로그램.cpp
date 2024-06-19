#include<iostream>
#include <vector>
#include <utility>

using namespace std;
//          x     y    k
//int board[2002][2002][22];
//vector<int> points[22]; //K���� ��
vector<vector<pair<int, int>> > points;
//K���� ���ڸ� �ε����� ����ϴ� ���! 
// points[0]: k=1 ������ ��ǥ���� ���� �迭
// points[1]: k=2 ������ ��ǥ  ..
// points[K-1]���� ����
int ans; //���� --�ִ� 2000 * 2000
int n, K;
void dfs(int cnt, int minX, int maxX, int minY, int maxY) {
    if (cnt == K) { //���� ����
        int area = (maxX - minX) * (maxY - minY);
        if (ans > area) ans = area;
        return;
    }
    //cnt(����)�� 0���� K-1���� Ž��
    for (int i = 0; i < points[cnt].size(); i++) {
        int x = points[cnt][i].first; // {x,y} �� x
        int y = points[cnt][i].second;// {x,y} �� y
        int minX2 = minX;
        int maxX2 = maxX;
        int minY2 = minY;
        int maxY2 = maxY;
        if (minX > x) minX2 = x; //�ּڰ� ���Ҷ� 1e9�� �ſ� ū���̹Ƿ� �ٷ� ����
        if (maxX < x) maxX2 = x; //�ִ� ���Ҷ� -1e9�� �ſ� �������̹Ƿ� ����
        if (minY > y) minY2 = y;
        if (maxY < y) maxY2 = y;
        //�ʱ⿡�� minX2=maxX2 ,minY2=maxY2 ���Ƽ� area=0
        int area = (maxX2 - minX2) * (maxY2 - minY2);
        //ans �ʱ갪 :�ſ� ū �� ==>���Ѵ�(1e9)
        //������Ʈ�� dfs() return �Ǿ� ���ƿ��� ��� �״�� �ּڰ� ans�� ����
        //���� ���� area���� ��
        if (ans <= area) { //���� ���ϴ� ���� �ּڰ� ���ϴ� ���̹Ƿ�!
            continue; //for�� �ε��� ����
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
    dfs(0, 1e9, -1e9, 1e9, -1e9); //�ſ� ū ������ 1e9 �̿�
    cout << ans << '\n';
    // for(auto a:v){
    //     cout<<a.first.first<<' '<<a.first.second<<' '<<a.second<<'\n';
    // }

    return 0;
}