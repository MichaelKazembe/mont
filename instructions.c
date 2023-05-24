#include "monty.h"

instruction_t instructions[] = {
    {"push", push_func},
    {"pall", pall_func},
    {"pint", pint_func},
    /* ... other instructions ... */
    {NULL, NULL}
};
