#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../include/SolvEqu.h"
#include "../include/io.h"
#include "../include/test.h"
#include "../include/ComLinePars.h"


/**
 * @brief checking for flags in the command line 
 * 
 * Running tests or printing help
 * depending on user's input
 *
 */
int ComPars(char** argv, int argc)          //argc, argv 
{
    int TEST_FLAG  = 1;
    int HELP_FLAG  = 2;
    int ret_value  = 0;
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-test"))
        {
            ret_value = ret_value | TEST_FLAG;
        }
        else if (!strcmp(argv[i], "-help"))
        {
            ret_value = ret_value | HELP_FLAG;
        }
    }
    
    return ret_value;
}