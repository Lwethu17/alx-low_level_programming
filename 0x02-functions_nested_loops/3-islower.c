#include "main.h"

/**
 * _islower - Checks for lowecase character
 * @c: The character to be checked or 0 for anything else
 *Return: 1 if char is lowercase, otherwise 0.
 */

int _islower(int c)

{
	if (c >= 97 && c <= 122)
	{

	return (1);
	}
	return (0);
}
