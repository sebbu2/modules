#include <stdio.h>
#include <string.h>

#ifdef __WIN32__
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

void EXPORT Pwet(char *buffer)
{
    strcpy(buffer, "Pwet !\n");
}
