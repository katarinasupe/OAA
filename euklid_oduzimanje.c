unsigned int NZM(unsigned int a, unsigned int b)
{
    if( a == b )
    {
        return a;
    }
    else if(a > b)
    {
        NZM(a - b, b);
    }
    else
    {
        NZM(a, b - a);
    }
}