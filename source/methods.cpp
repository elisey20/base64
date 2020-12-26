#include "structs.h"

char* to_b64(const char* str)
{
    int strlen = 0;
    int i = 0;
    while (str[i++] != '\0')
        strlen++;
    while (strlen / 6 != 0)
        strlen++;

}