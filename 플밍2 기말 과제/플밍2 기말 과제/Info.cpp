#include "Info.h"

Info::Info()
{
	Line = 0;
}

int Info::GetLine()
{
	return Line;
}

void Info::printInfo(string a)
{
	info[Line] = a;
	cout << "¡ß" << info[Line] << endl;
	Line++;
}

void Info::printInfo(string s1, int i, string s2)
{
	info[Line] = s1 + to_string(i) + s2;
	cout << "¡ß" << info[Line] << endl;
	Line++;
}

void Info::SaveInfo()
{
	for (int i = 0; i < Line; i++)
	{
		cout << "¡ß" << info[i] << endl;
	}
}

void Info::ResetLine()
{
	Line = 0;
}
