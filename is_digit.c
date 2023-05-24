#include "monty.h"

/**
 * is_digit - Checks if a string represents a valid number
 * @str: The string to check
 * Return: true if the string is a valid number, false otherwise
 */
bool is_digit(const char *str)
{
    if (str == NULL || *str == '\0')
        return false;

    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;

    bool has_digits = false;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
        
        has_digits = true;
    }

    return has_digits;
}
