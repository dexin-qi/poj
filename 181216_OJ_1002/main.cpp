#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

char _tChar2Num(char);

typedef struct
{
	char phoneStr[10];
	int occTimes;
}_stPhone;


int main()
{
	long memberLength = 0;
	cin >> memberLength;
	//cin.ignore('\n');

	vector<_stPhone> phoneVec;
	while (memberLength >= 0)
	{
		memberLength--;

		char phoneStrRaw[50] = { 0 };
		cin.getline(phoneStrRaw, 49);

		char phoneStrOut[10] = { 0 };
		short iter_count = 0;
		for (char *phoneChar = phoneStrRaw; *phoneChar != 0; phoneChar++)
		{
			char c = *phoneChar;
			if (c <= '9' && c >= '0')
			{
				if (iter_count == 3)
				{
					phoneStrOut[iter_count] = '-';
					iter_count++;
				}
				phoneStrOut[iter_count] = c;
				iter_count++;
			}
			else if (c != 'Q' && c <= 'Y' && c >= 'A')
			{
				if (iter_count == 3)
				{
					phoneStrOut[iter_count] = '-';
					iter_count++;
				}
				phoneStrOut[iter_count] = _tChar2Num(c);
				iter_count++;
			}
		}

		//cout << " out:" << phoneStrOut << endl;

		bool _sgGotSame = false;
		for (int i = 0; i < phoneVec.size(); i++)
		{
			if (strcmp(phoneVec[i].phoneStr, phoneStrOut) == 0)
			{
				_sgGotSame = true;
				phoneVec[i].occTimes++;
			}
		}
		if (!_sgGotSame)
		{
			_stPhone _tmpPhone;
			_tmpPhone.occTimes = 1;
			strcpy(_tmpPhone.phoneStr, phoneStrOut);
			phoneVec.push_back(_tmpPhone);
		}
	}

	vector<_stPhone> repeatPhoneVec;
	for (int i = 0; i<phoneVec.size(); i++)
	{
		if (phoneVec[i].occTimes != 1)
		{
			repeatPhoneVec.push_back(phoneVec[i]);
		}
	}

	for (int i = 0; i<repeatPhoneVec.size(); i++)
	{
		for(int j = 0; j < i; j++)
		{
			if (strcmp(repeatPhoneVec[i].phoneStr ,repeatPhoneVec[j].phoneStr) < 0)
			{
				_stPhone _tmpPhone = repeatPhoneVec[i];
				repeatPhoneVec[i] = repeatPhoneVec[j];
				repeatPhoneVec[j] = _tmpPhone;
			}
		}
	}

	for (int i = 0; i<repeatPhoneVec.size(); i++)
	{
		cout << repeatPhoneVec[i].phoneStr << " " << repeatPhoneVec[i].occTimes << endl;
	}
	
	return 0;
}

char _tChar2Num(char charRaw)
{
	char charOut = 0;

	if (charRaw < 'Q')
	{
		charOut = '2' + (charRaw - 'A') / 3;
	}
	else if (charRaw > 'Q')
	{
		charOut = '7' + (charRaw - 'Q') / 3;
	}
	
	return charOut;
}
