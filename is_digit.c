#include "monty.h"


int is_integer(char *str)
{
        if (*str == '-' || *str == '+')
                str++;
        if (*str == '\0')
                return (0);
        while (*str)
        {
                if (*str < '0' || *str > '9')
                        return (0);
                str++;
        }
        return (1);
}
