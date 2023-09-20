#include <string>
#include <vector>
#include <utility> //swap
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players); //복사생성자
    
    map<string,int> m1; //플레이어 이름 순위
    
    for(int i=0;i<players.size();i++){ //초기 순위 
        m1[players[i]]=i;
    }
    for(int i=0;i<callings.size();i++){
        //map에 <이름,순위> 저장
        int loc=m1[callings[i]]; //호출된 이름의 "순위( O(logn) 탐색)"를 loc에 저장
        m1[answer[loc-1]]+=1; // 그 순위 앞에 있는 원소 순위 변경
        m1[callings[i]]-=1; //호출 이름 순위 앞으로 땡겨짐
        
        //순위변경되었으니 answer배열 순서도 변경해야지?
        swap(answer[loc],answer[loc-1]);
    }
    
    
    
    return answer;
}
