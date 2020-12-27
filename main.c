#include <stdio.h>
#include <stdlib.h>


/*Nalazenje najvece zajednicke mjere dvaju prirodnih brojeva Euklidovim algoritmom s oduzimanjem.*/
unsigned int nzm_oduzimanjem(unsigned int a, unsigned int b)
{
    if( a == b )
    {
        return a;
    }
    else if(a > b)
    {
        nzm_oduzimanjem(a - b, b);
    }
    else
    {
        nzm_oduzimanjem(a, b - a);
    }
    return 0;
}

/*Nalazenje najvece zajednicke mjere dvaju prirodnih brojeva Euklidovim algoritmom s dijeljenjem s ostatkom.*/
unsigned int nzm_dijeljenje_s_ostatkom(unsigned int a, unsigned int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else{
        return nzm_dijeljenje_s_ostatkom(b, a % b);
    }
}


/*Nalazenje najvece zajednicke mjere dvaju prirodnih brojeva binarnim Euklidovim algoritmom.*/
unsigned int binarni_nzm(unsigned int a, unsigned int b)
{
    if(a == b)
    {
        return a;
    }
    else if(a == 0)
    {
        return b;
    }
    else if(b == 0)
    {
        return a;
    }
    else if((a & 1) == 0)
    {
        if((b & 1) == 0)
        {
            return 2 * binarni_nzm(a >> 1, b >> 1);
        }
        else
        {
            return binarni_nzm(a >> 1, b);
        }
    }
    else if((a & 1) != 0)
    {
        if((b & 1) == 0)
        {
            return binarni_nzm(a, b >> 1);
        }

        else if((a > b) && ((b & 1) != 0))
        {
            return binarni_nzm((a - b) >> 1, b);
        }
        else
        {
            return binarni_nzm((b - a) >> 1, a);
        }
    }

    return 0;
}

int main()
{
    printf("Najveca zajednicka mjera brojeva %d i %d je %d.\n", 28, 4, binarni_nzm(28, 4));
    printf("Najveca zajednicka mjera brojeva %d i %d je %d.\n", 49, 14, binarni_nzm(49, 14));
    printf("Najveca zajednicka mjera brojeva %d i %d je %d.\n", 2322, 654, binarni_nzm(2322,654));

    return 0;
}
