else if( ((a & 1) == 0) && ((b & 1) != 0) )
{
	 return binarni_nzm(a >> 1, b);
}
else if( ((a & 1) != 0) && ((b & 1) == 0) )
{
	return binarni_nzm(a, b >> 1);
}
else if( ((a & 1) != 0) && ((b & 1) != 0) && (a > b) )
{
	return binarni_nzm((a - b) >> 1, b);
}