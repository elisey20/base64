#include <iostream>
#include <cstring>
#include "structs.h"
#include "methods.h"

#define SAY std::cout <<

int main(int argc, char** argv)
{
    bool flag = true;
    for (int i = 0; i < argc && flag; i++)
    {
        if (strcmp(argv[i], "-i")) {
            SAY "Введите сообщение для кодирования:\t";
            flag = false;
        }
    }

    char* str = new char[1024];
    std::cin.getline(str, 1024);

    const char* res = to_b64(str);

    if (!flag)
        SAY "Сообщение в кодировке base64:\t\t";
    SAY res << std::endl;

    if (!flag)
        SAY "Декодированное сообщение:\t\t\t";
    SAY from_b64(res) << std::endl;

    delete[] res;
    delete[] str;

    return 0;
}
