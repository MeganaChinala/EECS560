#include <iostream>
#include "Executive.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Check parameter list!\n";
    }
    else
    {
        Executive exec(argv[1]);
    }

    return (0);
}
