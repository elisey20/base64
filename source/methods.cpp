#include <cmath>
#include <algorithm>
#include "structs.h"

char* to_b64(const char* str)
{
    int strlen = 0;
    while (str[strlen] != '\0')
        strlen++;

    int* count = new int;
    *count = ceil(strlen * 4 / 3.0);
    char* res = new char[*count + 1];
    delete count;

    int i = 0;
    int resI = 0;

    while (i < strlen)
    {
        char chr1 = str[i++];
        char chr2 = str[i++];
        char chr3 = str[i++];

        // Сдвигаем на 2 бита вправо и получаем 6 бит
        char enc1 = (unsigned char)chr1 >> 2;
        //enc1 = enc1 & 0x7F;
        // Берем 2 последних бита chr1 и складываем их с четырьмя из chr2
        char enc2 = (((unsigned char)chr1 & 3) << 4) | ((unsigned char)chr2 >> 4);
        //enc2 = enc2 & 0x7F;
        // Берем 4 последних бита chr2 и складываем их с двумя из chr3
        char enc3 = (((unsigned char)chr2 & 15) << 2) | ((unsigned char)chr3 >> 6);
        //enc2 = enc2 & 0x7F;
        // Берем 6 последних бит из chr3
        char enc4 = (unsigned char)chr3 & 63;
        //enc1 = enc1 & 0x7F;

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

    res[resI] = '\0';

    return res;
}

char* from_b64(const char* str)
{
    int strlen = 0;
    while (str[strlen] != '\0')
        strlen++;

    int* count = new int;
    *count = strlen * 3 / 4;
    char* res = new char[*count + 1];
    delete count;

    int i = 0;
    int resI = 0;

    while (i < strlen)
    {
        char chr1 = std::find(b64, b64 + 65, str[i++]) - b64;
        char chr2 = std::find(b64, b64 + 65, str[i++]) - b64;
        char chr3 = std::find(b64, b64 + 65, str[i++]) - b64;
        char chr4 = std::find(b64, b64 + 65, str[i++]) - b64;

        if (chr3 == 64)
        {
            chr3 = chr4 = '\0';
        }
        else if (chr4 == 64)
        {
            chr4 = '\0';
        }

        // Сдвигаем на 2 бита влево первый байт и вправо на 4 бита второй байт
        char dec1 = (chr1 << 2) | (chr2 >> 4);
        // Сдвигаем на 4 бита влево второй байт и вправо на 2 бита третий байт
        char dec2 = (chr2 << 4) | (chr3 >> 2);
        // Сдвигаем на 6 бит влево третий байт и складываем с 4 байтом
        char dec3 = (chr3 << 6) | chr4;

        res[resI++] = dec1;
        res[resI++] = dec2;
        res[resI++] = dec3;
    }

    res[resI] = '\0';

    return res;
}