/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define SIZE 31

char ** commonWords(char *str1, char *str2)

{
	if (str1 == NULL || str2 == NULL)
		return NULL;
	else
	{
		int index1 = 0, index2 = 0, index3 = 0, flag1 = 0, flag2 = 0, result1 = 0, result2 = 0;
		char words1[10][31] = { "\0" }, **words = (char **)malloc(10 * sizeof(char*));
		for (int index = 0; index < 10; index++)
		{
			words[index] = (char *)malloc(sizeof(char) * 31);
		}
		words[0][0] = '\0';

		while (str1[index1] != '\0')
		{
			if (str1[index1] != ' ')
			{
				while (str1[index1] != ' ' && str1[index1] != '\0')
				{
					words1[index3][index2++] = str1[index1];
					index1++;
				}
				words1[index3][index2] = '\0';
				index2 = 0;
				index3++;
			}
			else
				index1++;
		}
		int count1 = index3 - 1;
		index3 = 0;
		index1 = 0;
		if (words1[0][0] == '\0')
			return NULL;
		//compare
		while (index3 != count1)
		{
			while (str2[index1] != '\0')
			{
				if (str2[index1] == words1[index3][0])
				{
					int count2 = index1;
					while (words1[index3][index2] != '\0')
					{
						if (words1[index3][index2] == str2[index1])
						{
							words[result1][index2] = str2[index1];
							index1++;
							index2++;
							if (words1[index3][index2 + 1] != str2[index1 + 1])
							{
								if (words1[index3][index2 + 1] != '\0')
								{
									words[result1][index2 - 1] = '\0';
									flag1 = 1;
								}
							}
						}

						else
						{
							result1--;
							index2--;
							break;
						}
					}
					if (flag1 == 1)
					{
						result1++;
						flag1 = 0;
					}
					words[result1][index2] = '\0';
					result1++;
				}
				else
					index1++;
			}
			index3++;
			index1 = 0;
			index2 = 0;
		}
		if (words[0][0] == '\0')
			return NULL;
		else
			return words;
	}
}