//하노이탑
#include <bits/stdc++.h>

using namespace std;

//void func(int n) { //n개를 기둥1->기둥3 옮기는 방법 출력
void func(int a,int b,int n){ //n개를 a번 기둥에서 b번 기둥으로 옮겨
	                          //결론은 1번기둥에서 3번 기둥으로 옮기는 것

	
	//재귀..base condition(1원판을 기둥1에서 기둥3으로)
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	//n-1개를 기둥1에서 기둥2로 , n번원판을 기둥3으로
	func(a, 6 - a - b, n-1);
	//n번 원판 기둥a->b
	cout << a << ' ' << b << '\n';
	//n-1개를 기둥 2에서 기둥3으로 
	func(6 - a - b, b, n - 1);

}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; //원판개수
	//옮긴 횟수
	cout << (1 << n) - 1 << '\n'; //비트연산자 1을 비트 기준 왼쪽 n칸 밀어 
	func(1, 3, n);
	
	return 0;
}