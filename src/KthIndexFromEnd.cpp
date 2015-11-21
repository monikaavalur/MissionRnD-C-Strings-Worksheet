/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
char KthIndexFromEnd(char *str, int K)
{
	int len = 0, index;
	if (str == NULL || str == "" || K < 0)
		return '\0';
	while (str[len] != '\0')
		len++;
	if (K > len)
		return '\0';
	for (index = 0; index<len; index++)
	{
		if (index == K)
			break;
	}
	 
	return str[len-index-1];
}