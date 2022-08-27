#include <stdio.h>
#include <math.h>
#include <string.h>
#include "SolvEqu.h"
#include "io.h"
#include "test.h"


/**
 * @brief checking for flags in the command line 
 * 
 * Running tests or printing help
 * depending on user's input
 *
 */
void com_pars(char argv[])
{
    if (!strcmp(argv, "-test"))
    {
        test_solv_equ();
    }
    else if (!strcmp(argv, "-help"))
    {
        show_help();
    }
}