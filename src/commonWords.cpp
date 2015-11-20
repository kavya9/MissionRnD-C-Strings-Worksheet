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

#define SIZE 31
int compare(char s1[], char s2[])
{
	int i = 0, flag = 0;
	while (s1[i] != '\0'&&s2[i] != '\0')
	{
		if (s1[i] != s2[i]){ flag++; break; }
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')flag = 1;
	return flag;
}
char ** commonWords(char *str1, char *str2) {
	if(str1==NULL || str2==NULL) return NULL;
	int i = 0, p1, p2, q, j,flag=0;
	char **ans1 = (char **)calloc(100, sizeof(char *));
	for (i = 0; i<100; i++)
		ans1[i] = (char *)calloc(31, sizeof(char));

	char **ans2 = (char **)calloc(100, sizeof(char *));
	for (i = 0; i<100; i++)
		ans2[i] = (char *)calloc(31, sizeof(char));

	char **ans = (char **)calloc(100, sizeof(char *));
	for (i = 0; i<100; i++)
		ans[i] = (char *)calloc(31, sizeof(char));

	i = 0; p1 = 0; q = 0;
	while (str1[i] != '\0')
	{
		q = 0;
		while (str1[i] != ' '&&str1[i] != '\0')
		{
			ans1[p1][q] = str1[i];
			q++;
			i++;
		}
		ans1[p1][q] = '\0';
		p1++;
		if (str1[i] == ' ')i++;
	}
	if (q == 0)return NULL;
	i = 0; p2 = 0; q = 0;
	while (str2[i] != '\0')
	{
		q = 0;
		while (str2[i] != ' '&&str2[i] != '\0')
		{
			ans2[p2][q] = str2[i];
			q++;
			i++;
		}
		ans2[p2][q] = '\0';
		p2++;
		if (str2[i] == ' ') i++;
	}
	if (q == 0)return NULL;
	q = 0;
	for (i = 0; i<p1; i++)
	{
		for (j = 0; j<p2; j++)
		{
			if (!compare(ans1[i], ans2[j]))
			{
				ans[q] = ans1[i];
				q++;
				flag++;
			}
		}
	}
	if (flag == 0)return NULL;
	return ans;	
}