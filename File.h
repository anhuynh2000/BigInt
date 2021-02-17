#ifndef _FILE_
#define _FILE_

#include <iostream>
#include <string>

#define MAX 40


using namespace std;

struct QInt
{
	int data[4];
};

int 	Dec(bool bit[], int i);
void 	Bin(char s[MAX], bool bit[]);

void	Input();
void	PrintQInt(QInt x);
void 	InitEmptyBit(bool bittemp[128]);
void 	Output(bool bit[]);
void 	ScanQInt(bool bit[], QInt &x);

void 	reverseString(string &s);
QInt	StringToQInt(string s);



#endif
