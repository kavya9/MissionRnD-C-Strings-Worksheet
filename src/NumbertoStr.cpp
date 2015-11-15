/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void number_to_str(float number, char *str,int afterdecimal){
	int intPart, fracToInt,p=0,i,flag=0;
	float fracPart;
	char temp;
	temp = afterdecimal;
	if (number<0){ number *= -1; flag = 1; }
	intPart = number;
	fracPart = number - intPart;
	//converting fraction part into integer with "afterdecimal" no of digits
	while (afterdecimal > 0)
	{
		fracPart = 10 * fracPart;
		afterdecimal--;
	}
	fracToInt = fracPart;
	//converting fraction part to string
	while (fracToInt>0)
	{
		str[p] = (fracToInt % 10) + 48;
		fracToInt /= 10;
		p++;
	}
	if (temp != 0)
	{
		str[p] = '.';
		p++;
	}
	//converting integer part to string
	while (intPart>0)
	{
		str[p] = (intPart % 10) + 48;
		intPart /= 10;
		p++;
	}
	if (flag)
	{
		str[p] = '-';
		p++;
	}
	str[p] = '\0';
	p = --p;
	i = 0;
	//reversing the string
	while (i<p)
	{
		temp = str[i];
		str[i] = str[p];
		str[p] = temp;
		i++;
		p--;
	}
}
