#include "Calculator.h"
#include <iostream>
#include "File.h"
#include "Convert.h"
using namespace std;


void Addition(QInt x, QInt y, bool bit[128])
{
	
	bool *bit1 = QIntToBin(x);
	bool *bit2 = QIntToBin(y);
	
	int carry = 0;
	for (int i = 0; i < 128; i++)
	{
		if (carry == 0)
		{
			if ((bit1[i] == 1) && (bit2[i] == 1)) 
			{
				bit[i] = 0;
				carry = 1;
			}
			if (((bit1[i] == 1) && bit2[i] == 0) || ((bit1[i] == 0) && (bit2[i] == 1)))
			{
				bit[i] = 1;
				carry = 0;
			}
			if ((bit1[i] == 0) && (bit2[i] == 0))
			{
				bit[i] = 0;
				carry = 0;
			}
		}
		else 
		{
			if ((bit1[i] == 1) && (bit2[i] == 1)) 
			{
				bit[i] = 1;
				carry = 1;
			}
			if (((bit1[i] == 1) && bit2[i] == 0) || ((bit1[i] == 0) && (bit2[i] == 1)))
			{
				bit[i] = 0;
				carry = 1;
			}
			if ((bit1[i] == 0) && (bit2[i] == 0))
			{
				bit[i] = 1;
				carry = 0;
			}
		}
	}
}

void Subtraction(QInt x, QInt y, bool bit[128])
{
	bool *bit1 = QIntToBin(x);
	bool *bit2 = QIntToBin(y);
	
	int carry = 0;
	for (int i = 0; i < 128; i++)
	{
		if (carry == 0)
		{
			if ((bit1[i] == 1) && (bit2[i] == 1)) 
			{
				bit[i] = 0;
				carry = 1;
			}
			if ((bit1[i] == 1) && bit2[i] == 0)
			{
				bit[i] = 1;
				carry = 0;
			}
			if ((bit1[i] == 0) && (bit2[i] == 1))
			{
				bit[i] = 1;
				carry = 1;
			}
			if ((bit1[i] == 0) && (bit2[i] == 0))
			{
				bit[i] = 0;
				carry = 0;
			}
		}
		else 
		{
			if (bit1[i] == bit2[i])
			{
				bit[i] = 1;
				carry = 1;
			}
			if ((bit1[i] == 1) && bit2[i] == 0)
			{
				bit[i] = 0;
				carry = 0;
			}
			if ((bit1[i] == 0) && (bit2[i] == 1))
			{
				bit[i] = 0;
				carry = 1;
			}
		}
	}
	
	for (int i = 127; i >= 0; i--)
		if ((bit1[i] > bit2[i]))
		{
			for (int j = 127; j >= 0; j--)
			{	
				if ((bit1[j] == 1) && (bit2[j] == 1))
				{
					for (int k = j; k < 128; k++)
						bit[k] = 0;
					break;
				}
			}
			break;
		}
}
