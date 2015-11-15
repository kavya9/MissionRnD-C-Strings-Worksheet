/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void revString(char *s, int len)
{
	int i = 0, j = 0;
	char temp;
	j = len - 1;
	for (i = 0; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
void str_words_in_rev(char *input, int len){
	int i , j;
	revString(input, len);
	i = 0; j = 0;
	while (1)
	{
		if (input[j] == ' ' || input[j] == '\0')
		{
			revString(input + i, j - i);
			i = j + 1;
		}

		if (input[j] == '\0')break;
		j++;
	}
}
