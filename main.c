#include <stdio.h>
#include <stdlib.h>

/*DOMACA ZADACA: Nalazenje najvece zajednicke mjere dvaju prirodnih brojeva binarnim Euklidovim algoritmom.*/
//rekurzivna verzija algoritma -> ova verzija je objasnjena u prezentaciji (8 grana)
unsigned int binarni_nzm(unsigned int a, unsigned int b)
{
    //ako je a = b -> NZM(a,b) = a
    if(a == b)
    {
        return a;
    }
    //ako je a = 0 -> NZM(a,b) = b
    else if(a == 0)
    {
        return b;
    }
    //ako je b = 0 -> NZM(a,b) = a
    else if(b == 0)
    {
        return a;
    }
    //ako su a i b parni -> NZM(a,b) = 2 * NZM(a/2, b/2)
    else if( ((a & 1) == 0) && ((b & 1) == 0) )
    {
        return 2 * binarni_nzm(a >> 1, b >> 1);
    }
    //ako je a paran, b neparan -> NZM(a,b) = NZM(a/2, b)
    else if( ((a & 1) == 0) && ((b & 1) != 0) )
    {
         return binarni_nzm(a >> 1, b);
    }
    //ako je a neparan, b paran -> NZM(a,b) = NZM(a, b/2)
    else if( ((a & 1) != 0) && ((b & 1) == 0) )
    {
        return binarni_nzm(a, b >> 1);
    }
    //ako su a i b neparni i a > b -> NZM(a,b) = NZM((a-b)/2, b)
    else if( ((a & 1) != 0) && ((b & 1) != 0) && (a > b) ) //dovoljno je i samo a > b
    {
        return binarni_nzm((a - b) >> 1, b);
    }
    //ako su a i b neparni i a < b -> NZM(a,b) = NZM((b-a)/2, a)
    //else if(((a & 1) != 0) && ((b & 1) != 0) && (a < b) )
    else //dovoljno je samo else
    {
        return binarni_nzm((b - a) >> 1, a);
    }
}

/*DOMACA ZADACA: Nalazenje najvece zajednicke mjere dvaju prirodnih brojeva binarnim Euklidovim algoritmom.*/
//iterativna verzija algoritma
unsigned int binarni_nzm_iterativni(unsigned int a, unsigned int b)
{
    //ako je a = 0 -> NZM(a,b) = b
    if(a == 0)
    {
        return b;
    }
    //ako je b = 0 -> NZM(a,b) = a
    else if(b == 0)
    {
        return a;
    }

    //najveca potencija broja 2
    int k = 1;

    //racunaj najvecu potenciju broja 2 koja stane u oba broja
    while( ((a & 1) == 0) && ((b & 1) == 0) )
    {
        k <<= 1;
        a >>= 1;
        b >>= 1;
    }

    //dijeli a i b s 2 sve dok ne postanu neparni
    while( (a & 1) == 0 )
    {
        a >>= 1;
    }
    while( (b & 1) == 0 )
    {
        b >>= 1;
    }

    while( b != 0 )
    {
        if( a > b ) //zamjena vrijednosti
        {
            int temp = a;
            a = b;
            b = temp;
        }
        b = b - a;
    }

    return a * k;
}



int main()
{
    printf("Testni primjeri:\n");
    printf("  rekurzivna verzija    |    iterativna verzija\n");
    printf("---------------------------------------------------\n");
    printf("   NZM(%d, %d) = %d            ", 28, 4, binarni_nzm(28,4));
    printf("NZM(%d, %d) = %d\n", 28, 4, binarni_nzm_iterativni(28,4));
    printf("   NZM(%d, %d) = %d           ", 49, 14, binarni_nzm(49,14));
    printf("NZM(%d, %d) = %d\n", 49, 14, binarni_nzm_iterativni(49,14));
    printf("   NZM(%d, %d) = %d        ", 2322, 654, binarni_nzm(2322,654));
    printf("NZM(%d, %d) = %d\n", 2322, 654, binarni_nzm_iterativni(2322,654));
    printf("   NZM(%d, %d) = %d           ", 13, 11, binarni_nzm(13,11));
    printf("NZM(%d, %d) = %d\n", 13, 11, binarni_nzm_iterativni(13,11));
    printf("   NZM(%d, %d) = %d             ", 8, 9, binarni_nzm(8,9));
    printf("NZM(%d, %d) = %d\n", 8, 9, binarni_nzm_iterativni(8,9));
    printf("   NZM(%d, %d) = %d             ", 0, 0, binarni_nzm(0,0));
    printf("NZM(%d, %d) = %d\n", 0, 0, binarni_nzm_iterativni(0,0));
    printf("   NZM(%d, %d) = %d             ", 0, 5, binarni_nzm(0,5));
    printf("NZM(%d, %d) = %d\n", 0, 5, binarni_nzm_iterativni(0,5));
    printf("   NZM(%d, %d) = %d           ", 24, 0, binarni_nzm(24,0));
    printf("NZM(%d, %d) = %d\n", 24, 0, binarni_nzm_iterativni(24,0));
    printf("   NZM(%d, %d) = %d            ", 1, 65, binarni_nzm(1,65));
    printf("NZM(%d, %d) = %d\n", 1, 65, binarni_nzm_iterativni(1,65));
    printf("   NZM(%d, %d) = %d            ", 36, 1, binarni_nzm(36,1));
    printf("NZM(%d, %d) = %d\n", 36, 1, binarni_nzm_iterativni(36,1));
    printf("   NZM(%d, %d) = %d             ", 1, 1, binarni_nzm(1,1));
    printf("NZM(%d, %d) = %d\n", 1, 1, binarni_nzm_iterativni(1,1));
    printf("---------------------------------------------------\n");
    printf("\n");

    //proizvoljni unos za testiranje
    int a, b;

    do{
        printf("Ukoliko zelite izracunati najvecu zajednicku mjeru neka dva nenegativna broja, unesite prvi broj i stisnite Enter.\n");
        printf("Ukoliko zelite izaci, upisite -1 te stisnite Enter.\n");

        scanf("%d", &a);
        if(a == -1)
            break;
        else if(a < 0)
        {
            printf("Greska! Unijeli ste negativan broj!\n");
            break;
        }
        else{
            printf("Unesite drugi nenegativni broj:\n");
            scanf("%d", &b);
            if(b < 0)
            {
                printf("Greska! Unijeli ste negativan broj!\n");
                break;
            }
            printf("Najveca zajednicka mjera brojeva %d i %d je %d.\n", a, b, binarni_nzm(a,b));
            printf("\n");
        }
    }while(1);

    return 0;
}
