#include <iostream>
#include <string>
#include <math.h>
#include "Convert.h"
#include "File.h"
#define MAX 40

using namespace std;


bool *DecToBin(QInt x)
{
	bool *array = new bool[128];
	int byte = 3;
	int temp = 0;
	
	for (int i = 0; i < 128; i++)
		if (((i + 32) % 32) == 0)
		{
			temp = x.data[byte];
			if (temp >= 0)
				for (int j = i; j < (i + 32); j++)
				{
					array[j] = temp % 2;
					temp = temp / 2;
				}
			else 
				for (int j = i; j < (i + 32); j++)
				{
					if (temp % 2 == 0) array[j] = 1;
					else
					{
						array[i] = 1;
					}
					temp = temp / 2;
				}
			byte--;
		}
		
	for(int i = 0; i < 128 / 2; i++)
    {
      	int temp = array[i];
        array[i] = array[127 - i];
        array[127 - i] = temp; 
    }
    
	return array;
}

QInt BinToDec(bool bit[])
{
	QInt s;
	ScanQInt(bit, s);
	return s;
}

char *BinToHex(bool bit[])
{
	char *hex = new char[32];
	int pos = 0;
	int sum = 0;
	for (int i = 127; i >= 0; i--)
		if ((i + 1) % 4 == 0)
		{
			int count = 0;
			for (int j = i - 3; j <= i; j++)
			{
				if (bit[j] == 1)
					sum += pow(2, count);
				count++;
			}
			hex[pos] = sum + 48;
			if (sum > 9) hex[pos] += 7;
			sum = 0;
			pos++;
		}
	return hex;
}

bool *QIntToBin(QInt x)
{
	bool *array = new bool[128];
	int byte = 3;
	int temp = 0;
	
	for (int i = 0; i < 128; i++)
		if (((i + 32) % 32) == 0)
		{
			temp = x.data[byte];
			if (temp >= 0)
				for (int j = i; j < (i + 32); j++)
				{
					array[j] = temp % 2;
					temp = temp / 2;
				}
			else 
				for (int j = i; j < (i + 32); j++)
				{
					if (temp % 2 == 0) array[j] = 1;
					else
					{
						array[i] = 1;
					}
					temp = temp / 2;
				}
			byte--;
		}
	return array;
}

char  *DecToHex(QInt x)
{
	return BinToHex(QIntToBin(x));
}

