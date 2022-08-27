#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../include/SolvEqu.h"
#include "../include/io.h"
#include "../include/test.h"


/**
 * @brief checking for flags in the command line 
 * 
 * Running tests or printing help
 * depending on user's input
 *
 */
void ComPars(char* argv)
{
    // TEST_FLAG
    // HELP_FLAG
    // char ret_value = 0;

    if (!strcmp(argv, "-test"))
    {
        TestSolvEqu();
        //ret_value = ret_value | TEST_FLAG
    }
    else if (!strcmp(argv, "-help"))
    {
        ShowHelp();
    }
    // else INC_FLAG
}