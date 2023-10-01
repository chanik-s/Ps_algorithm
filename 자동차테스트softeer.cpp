#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,q;
int car[50000];
int m;

int main(int argc, char** argv)
{
	cin>>n>>q;
	for(int i=0;i<n;i++){ //자동차 n개
		cin>>car[i]; //연비 입력
	}
	sort(car,car+n); //연비 정렬

	for(int j=0;j<q;j++){  //질의 q개
		cin>>m; //테스트 결과 기댓값--질의에 대응하는 중앙값
		
		//binary search필요 lower_bound(시작,끝,찾는 key값)--iterator 반환
		int idx=lower_bound(car,car+n,m)-car; //찾으려는 key값 m

		if(idx!=n && m==car[idx]){ //m보다 car[idx]값들이 모두 작으면 idx=n반환하는데 car[n]은 인덱스 범위 벗어남
			cout<<idx*(n-idx-1)<<endl;
		}
		else{ //m이 연비 car[i]에 없는 숫자인 경우
			cout<<0<<endl;
		}

	}




	return 0;
}
