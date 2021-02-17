#include "File.h"
#include "Shift.h"
#include "Convert.h"
#include <iostream>

#define MAX 40
using namespace std;

void LeftShift(QInt x,  int n, bool bitresult[128])
{
	bool *bit = QIntToBin(x);

	for (int i = 0; i < 128; i++)
		bitresult[i] = 0;
	
	for (int i = 0; i < 128; i++)
		bitresult[i + n] = bit[i];
}

void RightLogicalShift(QInt x,  int n, bool bitresult[128])
{
	
	bool *bit = QIntToBin(x);
	
	for (int i = 0; i < 128; i++)
		bitresult[i] = 0;
	
	for (int i = 0; i < 128; i++)
		bitresult[i - n] = bit[i];
}

void RightArithmeticShift(QInt x,  int n, bool bitresult[128])
{
	bool *bit = QIntToBin(x);
	
	for (int i = 0; i < 128; i++)
		bitresult[i] = 0;
	
	for (int i = 0; i < 128; i++)
		bitresult[i - n] = bit[i];
		
	if (bit[0] == 1)	
		for (int i = 127; i >= 127 - n; i--)
			bitresult[i] = 1;
}
