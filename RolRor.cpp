#include "File.h"
#include "Shift.h"
#include "Convert.h"
#include <iostream>


using namespace std;

void Rol(QInt x,  int n, bool bitresult[128])
{
	bool *bit = QIntToBin(x);
	
	for (int i = 0; i < 128; i++)
		bitresult[i] = 0;
	
	for (int i = 0; i < 128; i++)
		bitresult[i + n] = bit[i];
		
	int pos = 0;
	for (int i = 128 - n; i < 128; i++)
	{
		bitresult[pos] = bit[i];
		pos++;	
	}
}

void Ror(QInt x,  int n, bool bitresult[128])
{
	bool *bit = QIntToBin(x);
	
	for (int i = 0; i < 128; i++)
		bitresult[i] = 0;
	
	for (int i = 0; i < 128; i++)
		bitresult[i - n] = bit[i];
		
	int pos = 0;
	for (int i = 128 - n; i < 128; i++)
	{
		bitresult[i] = bit[pos];
		pos++;	
	}
}
