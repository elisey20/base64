#include <iostream>
#include "structs.h"
#include "methods.h"

int main()
{
    const char* str = "foobar";

    const char* res = to_b64(str);

    std::cout << res;

    delete[] res;

    return 0;
}
