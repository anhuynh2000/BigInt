#include "Operator.h"
#include "Convert.h"
#include "File.h"
#include <iostream>

using namespace std;


bool CompareBinary(QInt x, QInt y, bool bitsum[128])
{
	bool *bit1 = QIntToBin(x);
	bool *bit2 = QIntToBin(y);
	int count = 0;
	for (int i = 127; i >= 0; i--)
	{
		if ((bit1[127] == 0) && (bit2[127] == 0))
		{
			if ((bit1[i] == 1) && (bit2[i] == 0))
			{
				return true;//1
				break;
			}
			if ((bit1[i] == 0) && (bit2[i] == 1))
			{
				return false;//0
				break;
			}
			if (bit1[i] == bit2[i]) count++;
		}
		
		if ((bit1[127] == 1) && (bit2[127] == 0))
		{ 
			return false;//0
			break;
		}
		
		if ((bit1[127] == 0) && (bit2[127] == 1))
		{
			return true;//1
			break;
		}
		
		if ((bit1[127] == 1) && (bit2[127] == 1))
		{
			if ((bit1[i] == 1) && (bit2[i] == 0))
			{
				return true;//1
				break;
			}
			if ((bit1[i] == 0) && (bit2[i] == 1))
			{
				return false;//0
				break;
			}
			if (bit1[i] == bit2[i]) count++;
		}
	}
}

bool EqualBinary(QInt x, QInt y, bool bitsum[128])
{
	bool *bit1 = QIntToBin(x);
	bool *bit2 = QIntToBin(y);
	int count = 0;
	for (int i = 127; i >= 0; i--)
	{
		if ((bit1[127] == 0) && (bit2[127] == 0))
		{
			if ((bit1[i] == 1) && (bit2[i] == 0))
			{
				break;
			}
			if ((bit1[i] == 0) && (bit2[i] == 1))
			{
				break;
			}
			if (bit1[i] == bit2[i]) count++;
		}
		
		if ((bit1[127] == 1) && (bit2[127] == 0))
		{
			break;
		}
		
		if ((bit1[127] == 0) && (bit2[127] == 1))
		{
			break;
		}
		
		if ((bit1[127] == 1) && (bit2[127] == 1))
		{
			if ((bit1[i] == 1) && (bit2[i] == 0))
			{
				break;
			}
			if ((bit1[i] == 0) && (bit2[i] == 1))
			{
				break;
			}
			if (bit1[i] == bit2[i]) count++;
		}
	}
	if (count == 128) return true;
	else return false;
}

void AndCalculator(QInt x, QInt y, bool bit[128])
{
	bool *bit1 = QIntToBin(x);
	bool *bit2 = QIntToBin(y);
	
	for (int i = 127; i >= 0; i--)
	{
		if ((bit1[i] == 0) && (bit2[i] == 0)) bit[i] = 0;
		if (((bit1[i] == 1) && (bit2[i] == 0)) || ((bit1[i] == 0) && (bit2[i] == 1))) bit[i] = 0;
		if ((bit1[i] == 1) && (bit2[i] == 1)) bit[i] = 1;
	}
}

void OrCalculator(QInt x, QInt y, bool bit[128])
{
	bool *bit1 = QIntToBin(x);
	bool *bit2 = QIntToBin(y);
	
	for (int i = 127; i >= 0; i--)
	{
		if ((bit1[i] == 0) && (bit2[i] == 0)) bit[i] = 0;
		if (((bit1[i] == 1) && (bit2[i] == 0)) || ((bit1[i] == 0) && (bit2[i] == 1))) bit[i] = 1;
		if ((bit1[i] == 1) && (bit2[i] == 1)) bit[i] = 1;
	}
}

void XorCalculator(QInt x, QInt y, bool bit[128])
{
	bool *bit1 = QIntToBin(x);
	bool *bit2 = QIntToBin(y);
	
	for (int i = 127; i >= 0; i--)
	{
		if ((bit1[i] == 0) && (bit2[i] == 0)) bit[i] = 0;
		if (((bit1[i] == 1) && (bit2[i] == 0)) || ((bit1[i] == 0) && (bit2[i] == 1))) bit[i] = 1;
		if ((bit1[i] == 1) && (bit2[i] == 1)) bit[i] = 0;
	}
}

void NotCalculator(QInt x, bool bitresult[128])
{
	bool *bit = QIntToBin(x);
	
	for (int i = 127; i >= 0; i--)
	{
		if (bit[i] == 0) bitresult[i] = 1;
		else bitresult[i] = 0;
	}
}
