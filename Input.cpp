#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <string.h>

#include "Calculator.h"
#include "Operator.h"
#include "Convert.h"
#include "Shift.h"
#include "File.h"


using namespace std;

const char *INPUT = "input.txt";
const char *OUTPUT = "output.txt";


int checkSpace(vector<string> s)
{
	return s.size() - 1;
}
void reverseString(string &s)
{
	string temp = s;
	for(int i = 0; i < s.size(); i++)
	{
		s[i] = temp[s.size() - 1 - i];
	}	
}

void Input()
{	
	freopen(INPUT,"r",stdin);
	freopen(OUTPUT,"w",stdout);
	
	string cmd;
	
	while (getline(cin, cmd)) 
	{	
		stringstream ss(cmd);
		vector<string> s;
		
		while (ss >> cmd)
		{
			
            s.push_back(cmd);
		}
		
		bool bit[128];
		InitEmptyBit(bit);
		
		
		if (checkSpace(s) == 2 ) 
		{
			if (s[0] == "2") 
			{	
				reverseString(s[2]);
			}
			
			if (s[0] == "2" && s[1] == "10")
			{
			} 
			
		}
		else 
		{
			if (s[0] == "2") 
			{	
				reverseString(s[1]);
				reverseString(s[3]);
			}
						
			//Calculator
			if (s[2] == "+") 	
			{
				Addition(StringToQInt(s[1]),StringToQInt(s[3]),bit);
				Output(bit);
				InitEmptyBit(bit);

			}
			
			if (s[2] == "-")
			{
				Subtraction(StringToQInt(s[1]),StringToQInt(s[3]),bit);
				Output(bit);
			}
		 	

			//Compare 
			if (s[2] == ">") 	
			{
				CompareBinary(StringToQInt(s[1]),StringToQInt(s[3]),bit);
				Output(bit);
			}
			if (s[2] == "<") 	
			{
				CompareBinary(StringToQInt(s[3]),StringToQInt(s[1]),bit);
				Output(bit);
			}
			if (s[2] == "==")	
			{
				EqualBinary(StringToQInt(s[1]),StringToQInt(s[3]),bit);
				Output(bit);
			}
			
			//Bitwise operators
			if (s[2] == "&") // AND 
			{
				AndCalculator(StringToQInt(s[1]),StringToQInt(s[3]),bit);
				Output(bit);
			}
			if (s[2] == "|") // OR 
			{
				OrCalculator(StringToQInt(s[1]),StringToQInt(s[3]),bit);
				Output(bit);
			}
			if (s[2] == "^") // XOR
			{
				XorCalculator(StringToQInt(s[1]),StringToQInt(s[3]),bit);
				Output(bit);
			}
			if (s[2] == "~") // NOT
			{
				NotCalculator(StringToQInt(s[2]),bit);
				Output(bit);
			}
//			//Shift operator
//			if (s[2] == "<<") // left shift 
//			{
//				LeftShift(StringToQInt(s[1]),(int) s[3],bit);
//				Output(bit);
//			}
//			if (s[2] == ">>")  // right shift 
//			{
//				RightLogicalShift(StringToQInt(s[1]),(int) s[3],bit);
//				Output(bit);
//			}
//			if (s[2] == "rol") // turn left 
//			{
//				Rol(StringToQInt(s[1]),(int) s[3],bit);
//				Output(bit);
//			}
//			if (s[2] == "ror")	// turn right 
//			{
//				Ror(StringToQInt(s[1]),(int) s[3],bit);
//				Output(bit);
//			}
		}
	}
	
}

void InitEmptyBit(bool bittemp[128])
{
	for (int i = 0; i < 128; i++)
		bittemp[i] = 0;
}
void ScanQInt(bool bit[], QInt &x)
{
	int count = 3;
	for (int i = 0; i < 128; i++)
		if ((i + 32) % 32 == 0)
		{
			x.data[count] = Dec(bit, i); 
			count--;
		}
}
int Dec(bool bit[], int i)
{
	unsigned int sum = 0, temp = 0;
	for (int j = i; j < i + 32; j++)
	{
		if (bit[j] == 1)
		{
			sum += pow(bit[j] * 2, temp);
		}
		temp++;
	}
	return sum;
}

void Bin(char s[MAX], bool bit[])
{
	int rem = 0, quotient = 0;
	int i = 0, j = 0;
	
	if (s[0] != '-')
	{
		for (j = 0; j < 128; j++)
		{
			for (i = 0; i < strlen(s); i++)
			{
				rem = ((int)s[i] - 48) % 2;
				quotient = ((int)s[i] - 48) / 2;
				if ((rem == 1) && (i < (strlen(s) - 1)))
					s[i+1] = (s[i+1] - 48 + 10) + 48;
				s[i] = quotient + 48;
			}
			bit[j] = rem;
		}
	}
	
	else
	{
		for (j = 0; j < 128; j++)
		{
			for (i = 1; i < strlen(s); i++)
			{
				rem = ((int)s[i] - 48) % 2;
				quotient = ((int)s[i] - 48) / 2;
				if ((rem == 1) && (i < (strlen(s) - 1)))
					s[i+1] = (s[i+1] - 48 + 10) + 48;
				s[i] = quotient + 48;
			}
			if (rem == 1) 
			{
				bit[j] = 0;
				if ((j + 32) % 32 == 0) bit[j] = 1;
			}
			else bit[j] = 1;
		}
	}
}

QInt StringToQInt(string s)
{
	QInt x;
	char char_array[s.length() + 1];
	
	strcpy(char_array, s.c_str()); 

	bool bit[128];
		
	InitEmptyBit(bit);
	Bin(char_array,bit);
	ScanQInt(bit,x);
	
	return x;
}
 
