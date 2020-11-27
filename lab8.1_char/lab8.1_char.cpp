#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

int Find_Dot( char* s, const char c)
{
	int pos = strlen(s) - 4;
	char* t;

	while (t = strchr(s + pos - 1, '.'))
	{
		pos = t - s;
		if (s[pos] == '.')
			return pos;
	}
}

char* Change(char* s) 
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, '.'))
	{
		if (s[p - s] == '.')
		{
			pos2 = p - s + 1;
			strncat_s(t, (strlen(s)+pos2), s + pos1,  pos2 - pos1 - 1);
			strcat_s(t, (strlen(s)+pos2), "**");
			pos1 = pos2;
		}
	}

	strcat_s(t, (strlen(s)+pos2), s + pos1);

	strcpy_s(s, (strlen(s)+pos2), t);
	return t;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char str[101];
	const char c = '.';
	cout << " Введіть стрічку: " << endl;
	cin.getline(str, 100);

	cout << endl;

	cout << " length = " << strlen(str) << endl;
	
	cout << " Номер 4-ої крапки з кінця: " << Find_Dot(str, c) << endl;

	char* dest = new char[151];
	dest = Change(str);
	cout << " Модифікована стрічка: " << dest << endl;

	return 0;
}
