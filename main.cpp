#include <iostream>
#include "structs.h"
#include "methods.h"

int main()
{
    const char* str = "";
    const char* res = to_b64(str);

    std::cout << res << std::endl;

    std::cout << from_b64(res) << std::endl;

    delete[] res;

    return 0;
}
