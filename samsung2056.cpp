#include <iostream>
#include<string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		string input;
		string answer;
		
		cin >> input; //"2222 02 28" ÀÎµ¦½Ì ÇÊ¿ä
		//ÀÎµ¦½Ì Àß¸øµÊsubstrº¸±â
		string year=input.substr(0,4); //2022
		string month=input.substr(4,2); //02
		string day=input.substr(6,2); //28
		
		int num_m = stoi(month);
		if (num_m > 0&&num_m<=12 )
		{
			if (num_m == 1 ||num_m == 3 || num_m == 5 || num_m == 7 || num_m == 8 || num_m == 10 || num_m == 12)
			{
				if (stoi(day) >= 1 && stoi(day) <= 31) answer = year + '/' + month + '/' + day;
				else answer = "-1";
			}
			if (num_m == 4 || num_m == 6 || num_m == 9 || num_m == 11)
			{
				if (stoi(day) >= 1 && stoi(day) <= 30) answer = year + '/' + month + '/' + day;
				else answer = "-1";
			}
			if (num_m == 2)
			{
				if (stoi(day) >= 1 && stoi(day) <= 28) answer = year + '/' + month + '/' + day;
				else answer = "-1";
			}
		}
		else
			answer = "-1";

		cout << "#" << t << " " << answer << '\n';
	}

	return 0;
}