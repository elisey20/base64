#include <cmath>
#include "structs.h"

char* to_b64(const char* str)
{
    int strlen = 0;
    while (str[strlen] != '\0')
        strlen++;

    int* count = new int;
    *count = ceil(strlen * 4 / 3.0);
    char* res = new char[*count];
    delete count;

    int i = 0;
    int resI = 0;

    while (i < strlen)
    {
        char chr1 = str[i++];
        char chr2 = str[i++];
        char chr3 = str[i++];

        // Сдвигаем на 2 бита вправо и получаем 6 бит
        char enc1 = chr1 >> 2;
        // Берем 2 последних бита chr1 и складываем их с четырьмя из chr2
        char enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
        // Берем 4 последних бита chr2 и складываем их с двумя из chr3
        char enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
        // Берем 6 последних бит из chr3
        char enc4 = chr3 & 63;

        if (chr2 == '\0') {
            enc3 = enc4 = 64;
        } else if (chr3 == '\0') {
            enc4 = 64;
        }


        res[resI++] = b64[enc1];
        res[resI++] = b64[enc2];
        res[resI++] = b64[enc3];
        res[resI++] = b64[enc4];
    }

    return res;
}