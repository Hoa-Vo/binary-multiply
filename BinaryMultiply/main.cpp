#include"funtion.h"
int main()
{
	int c = 0;
	int m[8] = {0,1,0,0,1,0,1,1 };
	int q[8] = {0,0,1,0,1,1,0,1 };
	int a[8] = { 0 };
	int x = binaryToDec(m,8);
	int y = binaryToDec(q, 8);
	int result= multiplyBinary(c, a, m, q);
	cout << x << "x" << y << "=" << result;
	
}