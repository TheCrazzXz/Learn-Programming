#include <stdio.h>
#include "stdioFR.h"


int main(void)
{
    __ENTIER x = 0;

    ENTREE("_NOMBRE", x);

    SI(x == 0)
    {
        AFFICHER("Option 1 : x = 0\n");
    }

    SI(x == 1)
    {
        AFFICHER("Option 2 : x = 2\n");
    }

    AFFICHER("Bonjour");
    return 0;
}