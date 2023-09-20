#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    
    
    map<string,int> m1; //이름과 점수 저장
    for(int i=0;i<photo.size();i++){      //행 
        for(int j=0;j<photo[i].size();j++){  //열 (행개수!=열개수)
            m1[photo[i][j]]=0; //일단 0으로 초기화
        }
    }
    
    for(int i=0;i<name.size();i++){
        m1[name[i]]=yearning[i]; //그리움 점수
    }
    
    for(int i=0;i<photo.size();i++){
        int cnt=0;
        for(int j=0;j<photo[i].size();j++){
            cnt+=m1[photo[i][j]];
        }
        answer.push_back(cnt);
    }
    
    
    return answer;
}
