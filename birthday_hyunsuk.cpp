#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	//�Է�
	int T;
	int x, y;
	char N[100009] = { 0 };
	char res[100009] = { 0 };
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		cin >> x >> y;

		//�ַ��
		for (int i = 0; N[i] != '\0'; i++)
		{
			if (N[i] - '0' < x )  //x>N 
			{
			
			}
			if (N[i] - '0' >= x && N[i] - '0' < y ) // x<=N<y
			{
				if (N[i] - '0' != x)
				{
			
				}
				// x�� N �����Ҷ���
				res[i] = '0' + x;  //ex> '0'+8=> '8'��
				res[i + 1] = '\0'; //�迭 �� ǥ��
			}
			else {              //  x<y<=N

				if (N[i] - '0' > y)
				{
				
				}
				// y�� N �����Ҷ���
				res[i] = '0' + y;
				res[i + 1] = '\0';
			}
		}

		while (res[0] == '0') //?  N=>0237  ->237
		{
			for (int i = 0; res[i] != '\0'; i++)
			{
				res[i] = res[i + 1];
			}
		}

		if (strlen(res) == strlen(N) && strcmp(res, N) > 0)
		{
			res[strlen(res) - 1] = '\0';
		}

		if ( strlen(res) < strlen(N)) {
			for (int i = 0; res[i] != '\0'; i++)
			{
				res[i] = '0' + y;
			}
		}

	

		
		if () 	cout << "#" << t << " " << res << "\n";
		else    	cout << "#" << t << " " << -1 << "\n";
	}
	return 0;
}