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


void number_to_str(float number, char *str,int afterdecimal)
{
	int flag = 0, length = 0, remainder = 0, index = 0;
	//extracting decimal and integer part
	int integer = (int)number;
	float decimal = number - integer;
	//checking whether the number is positive or negative
	if (integer < 0)
		flag = 1;
	//finding length of the integer
	int num = integer;
	while (num != 0)
	{
		length++;
		num = num / 10;
	}
	//converting the integer into string
	if (flag == 1)
	{
		str[0] = '-';
		integer = -integer;
		for (index = 1; index <= length; index++)
		{
			remainder = integer % 10;
			integer = integer / 10;
			str[length - (index - 1)] = remainder + '0';
		}
	}
	else
	{
		for (index = 0; index < length; index++)
		{
			remainder = integer % 10;
			integer = integer / 10;
			str[length - (index + 1)] = remainder + '0';
		}
	}
	//creating the end of the string if afterdecimal=0
	if (afterdecimal == 0)
	{
		if (flag == 1)
			str[length + 1] = '\0';
		else
			str[length] = '\0';
	}
	//else converting the decimal part into number
	else
	{
	if (flag == 1)
	{
		length++;
		str[length] = '.';
	}
	else
		str[length] = '.';
	int result = 1;
	for (index = 0; index < afterdecimal; index++)
	{
		result *= 10;

	}
	num = decimal * result;
	if (flag == 1)
		num = -num;
	int reverse = 0;
	while (num != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + num % 10;
		num = num / 10;
	}
	for (index = 0; index < afterdecimal; index++)
	{
		remainder = reverse % 10;
		reverse = reverse / 10;
		str[length + (index + 1)] = remainder + '0';
	}
	str[length + index + 1] = '\0';
	
}
}
