#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED

#include <stdlib.h>

void print_error(char* module_name, char* err_msg, int is_critical)
{
    fprintf(stderr, "Module %s>  ", module_name);
    perror(err_msg);                         
//    fprintf(stderr, "\n");
    if(is_critical == 1) exit(1);
}

#endif // ERRORS_H_INCLUDED
