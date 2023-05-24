#include "monty.h"

/**
 * is_number - Checks if a string represents a valid number.
 * @str: The string to check.
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_number(char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;

    int has_digits = 0;

    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0;

        has_digits = 1;
    }

    return has_digits;
}
