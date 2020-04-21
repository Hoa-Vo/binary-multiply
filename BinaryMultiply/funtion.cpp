#include "funtion.h"
int multiplyBinary(int c, int a[], int m[], int q[])
{
	int k = 8;
	while (k > 0)
	{
		if (q[7] == 1)
		   addBinary(c, a, m);
		shiftRight(c, a, q);
		k--;
	}
	int temp[17] = { 0 };
	combineArray(c, a, q, temp);
	int result=binaryToDec(temp, 17);
	return result;
}
void addBinary(int& c, int a[], int m[])
{
	for (int i = 7; i >= 0; i--)
	{
		int temp = a[i] + m[i] + c;
		if (temp <= 1)
		{
			c = 0;
			a[i] = temp;
		}
		if (temp==2)
		{
			c = 1;
			a[i] = 0;
		}
		if (temp > 2)
		{
			c = 1;
			a[i] = 1;
		}
	}
}
void shiftRight(int& c, int a[], int q[])
{
	int temp[17] = { 0 };
	combineArray(c, a, q,temp);
	for (int i = 16; i > 0; i--)
	{
		temp[i] = temp[i - 1];
	}
	temp[0] = 0;
	splitArray(c,a, q, temp);
}
void combineArray(int c, int a[], int q[], int temp[])
{
	temp[0] = c;
	int index = 1;
	for (int i = 0; i < 8; i++)
	{
		temp[index++] = a[i];
	}
	for (int i = 0; i < 8; i++)
	{
		temp[index++] = q[i];
	}
}
void splitArray(int& c, int a[], int q[], int temp[])
{
	c = temp[0];
	int index = 1;
	for (int i = 0; i < 8; i++)
	{
		a[i] = temp[index++];
	}
	for (int i = 0; i < 8; i++)
	{
		q[i] = temp[index++];
	}
}
void printArray(int a[])
{
	for (int i = 0; i < 17; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int binaryToDec(int a[], int n)
{ 
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i] * pow(2, n - i - 1);
	return s;
}