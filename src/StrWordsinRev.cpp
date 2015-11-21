/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>

void StringRev(char *, int, int);
void StringWord(char *, int);
void str_words_in_rev(char *input, int len)
{
	StringRev(input, 0, len-1);
	StringWord(input, len);
}
void StringRev(char *input, int start, int len)
{
	int temp, index, index1;
	for (index = start, index1 = len ; index < index1; index++, index1--)
	{
		temp = input[index];
		input[index] = input[index1];
		input[index1]=temp;
	}
}
void StringWord(char *input, int len)
{
	int start =0, end = 0;
	while (end < len)
	{
		while (input[end] != ' '&&input[end] != '\0')
		{
			end++;
		}
		StringRev(input, start, end - 1);
		start = ++end;
	}
}
