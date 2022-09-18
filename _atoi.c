#include <limits.h>

/**
 * _atoi - converts strings to integer.
 * @str: string to be converted.
 *
 * Return: The converted integer.
 */

int _atoi(char *str)
{
	int sign = 1, result = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			continue;
		else if (str[i] >= 48 && str[i] <= 57)
			continue;
		else
			return (INT_MIN);
	}
	for (i = 0; !(str[i] >= 48 && str[i] <= 57); i++)
	{
		if (str[i] == '-')
			sign *= -1;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			result *= 10;
			result += (str[i] - 48);
		}
	}
	result *= sign;
	return (result);
}
