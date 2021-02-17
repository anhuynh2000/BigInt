#include <iostream>
#include <stdio.h>
#include <string>
#include "File.h"

using namespace std;

void PrintQInt(QInt x)
{
	for (int i = 0; i < 4; i++)
		cout << x.data[i] << " ";
	cout << endl;
}

void Output(bool bit[])
{
	for (int i = 127; i >= 0; i--)
	{
		cout << bit[i];
		if ((i % 32) == 0) cout << " ";
	}
	cout << endl;
}

