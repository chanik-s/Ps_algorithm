#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str;
	getline(cin,str);
	int alpha[26] = { 0 }; //¾ËÆÄºª ´ã´Â ±×¸© ÃÊ±â 0

	for (int i = 0; i < str.length(); i++)
	{
		char name='a';
		while (name >= 'a'&&name<='z') 
		{
			/*
			if (str[i] == 'a') alpha[0]++;
			if (str[i] == 'b') alpha[1]++;
			if (str[i] == 'c') alpha[2]++;
			if (str[i] == 'd') alpha[3]++;
			if (str[i] == 'e') alpha[0]++;
			if (str[i] == 'f') alpha[0]++;
			if (str[i] == 'g') alpha[0]++;
			*/
			if (str[i] == name) alpha[name - 'a']++;
			name++;
		}
		

	}
	for (int i = 0; i < 26; i++) { //¾ËÆÄºª °³¼ö
		cout << alpha[i] << ' ';
	}

	return 0;
}