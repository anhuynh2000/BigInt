#ifndef _BITWISE_
#define _BITWISE_

#define MAX 40

void	Rol(QInt x,  int n, bool bitresult[128]);
void	Ror(QInt x,  int n, bool bitresult[128]);
void 	LeftShift(QInt x,  int n, bool bitresult[128]);
void	RightLogicalShift(QInt x,  int n, bool bitresult[128]);
void	RightArithmeticShift(QInt x,  int n, bool bitresult[128]);

#endif
