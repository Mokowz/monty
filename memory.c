#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals.
 *         another value if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *mainter;
	int i = 0, j = 0;

	if (!s)
		s = mainter;
	while (s[i] != '\0')
	{
		if (search_char(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			mainter = s + i + 1;
			*mainter = '\0';
			s = s + j;
			return (s);
		}
		else if (search_char(d, s[i]) == 0 && search_char(d, s[i + 1]) == 0)
			i++;
		else if (search_char(d, s[i]) == 0 && search_char(d, s[i + 1]) == 1)
		{
			mainter = s + i + 1;
			*mainter = '\0';
			mainter++;
			s = s + j;
			return (s);
		}
		else if (search_char(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}

/**
 * search_char - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int search_char(char *s, char c)
{
	int count = 0;

	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			break;
		}
		count++;
	}
	if (s[count] == c)
		return (1);
	else
		return (0);
}
