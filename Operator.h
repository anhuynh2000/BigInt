#ifndef _OPERATOR_
#define _OPERATOR_

#define MAX 40
#include "File.h"

// Compare
bool CompareBinary(QInt x, QInt y, bool bitsum[128]); 
bool EqualBinary(QInt x, QInt y, bool bitsum[128]);

//Bitwise operator
void 	XorCalculator(QInt x, QInt y, bool bitsum[128]);
void	AndCalculator(QInt x, QInt y, bool bitsum[128]);
void	OrCalculator(QInt x, QInt y, bool bitsum[128]);
void	NotCalculator(QInt x, bool bitresult[128]);

#endif
