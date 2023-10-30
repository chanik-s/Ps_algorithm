#include <iostream>

using namespace std;

int n = 10;
//int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int arr[1000001];
int tmp[1000001]; // merge �Լ����� ����Ʈ 2���� ��ģ ����� �ӽ÷� �����ϰ� ���� ����

// mid = (st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� 
//�̹� ������ �Ǿ��ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ģ��.

//merge �Լ��� arr[st:en]�� �����ϴ� �Լ��Դϴ�. arr[st:en]�̶�� ǥ���� ���̽��� slicing ����(en ������)
void merge(int st, int en) {  // ��ġ��..! �� �ٿ��� O(N=>arr���� ����)�� �ʿ�
							  //(N=2^k)�� ���� k�� =logN
							//���� �ð����⵵ O(NlogN)
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;
	//�Ʒ��� �� ����Ʈ(a,b) "�������� �����Ͽ�" ��ġ��(c) ���������� ����
	for (int i = st; i < en; i++) {
		if (ridx == en) tmp[i] = arr[lidx++];      //������ ����Ʈ ��������
		else if (lidx == mid) tmp[i] = arr[ridx++];//���� ����Ʈ �������� 
		else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
		else tmp[i] = arr[ridx++];
	}
}
// arr[st:en]�� �����ϰ� �ʹ�.
void merge_sort(int st, int en) {
	if (en==st+1) return; // �迭 ���� 1�� ���
	int mid = (st + en) / 2;
	//���!!
	merge_sort(st, mid); // arr[st:mid]�� �����Ѵ�. st���� mid ������
	merge_sort(mid, en); // arr[mid:en]�� �����Ѵ�. mid���� en ������
	
	//�� ����Ʈ ����.....��, ���Ұ� 2���̻��� ����Ʈ�������͸� ��ġ�� ����(���� 1���� ����Ʈ ����) 
	merge(st, en); // arr[st:mid]�� arr[mid:en]�� ��ģ��.-->���ı��� �Ǵ°���
	//���� ó������ ���� 1�� �迭 ������
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