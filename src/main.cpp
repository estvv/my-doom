#include "all.hpp"
#include <cstring>
#include <iostream>

using namespace std;

int main(int ac, char **av)
{
    All all;

    if (ac == 1) {
        all.gameLoop();
        return 0;
    }
    if (ac == 2 and (strcmp(av[1], "-h") == 0 or strcmp(av[1], "--help") == 0)) {
        cout << "oui" << endl;
        return 0;
    }
    return 84;
}
