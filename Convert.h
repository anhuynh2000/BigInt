#ifndef _CONVERT_
#define _CONVERT_

#include "File.h"

char	*DecToHex(QInt x);
bool 	*DecToBin(QInt x);
bool 	*QIntToBin(QInt x);
char	*BinToHex(bool bit[]);

QInt 	BinToDec(bool bit[]);


#endif
