#include <iostream>

using namespace std;

int n = 10;
//int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int arr[1000001];
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 
//이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.

//merge 함수는 arr[st:en]을 정렬하는 함수입니다. arr[st:en]이라는 표현은 파이썬의 slicing 문법(en 미포함)
void merge(int st, int en) {  // 합치기..! 각 줄에서 O(N=>arr원소 개수)번 필요
							  //(N=2^k)줄 개수 k개 =logN
							//최종 시간복잡도 O(NlogN)
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;
	//아래는 두 리스트(a,b) "오름차순 정렬하여" 합치기(c) 예제문제와 동일
	for (int i = st; i < en; i++) {
		if (ridx == en) tmp[i] = arr[lidx++];      //오른쪽 리스트 다했으면
		else if (lidx == mid) tmp[i] = arr[ridx++];//왼쪽 리스트 다했으면 
		else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
		else tmp[i] = arr[ridx++];
	}
}
// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en) {
	if (en==st+1) return; // 배열 길이 1인 경우
	int mid = (st + en) / 2;
	//재귀!!
	merge_sort(st, mid); // arr[st:mid]을 정렬한다. st포함 mid 미포함
	merge_sort(mid, en); // arr[mid:en]을 정렬한다. mid포함 en 미포함
	
	//두 리스트 합쳐.....즉, 원소가 2개이상인 리스트에서부터만 합치기 가능(개수 1개인 리스트 제외) 
	merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.-->정렬까지 되는거임
	//가장 처음에는 길이 1인 배열 정렬함
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	merge_sort(0, n); //st=0 , en=n=10
	for (int i = 0; i < n; i++) cout <<arr[i] << ' ';

	return 0;
}