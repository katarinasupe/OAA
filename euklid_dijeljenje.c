unsigned int NZM(unsigned int a, unsigned int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else{
        return NZM(b, a % b);
    }
}