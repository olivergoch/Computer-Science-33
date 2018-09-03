static float u2f(unsigned u)
{
	typedef union result
    {
        unsigned un;
        float fl;
    }
    result.un = u;
    return result.fl;
}


float fpwr4(int x)
{
	/* Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;
	if(x < -75)
	{
        /* Too small. Return 0.0 */
		exp = 0;
		frac = 0;
	} 
	else if (x < -63)
	{
        /* Denormalized result */
		exp = 0;
		frac = 1 << (x + 149);
	}
	else if (x < 64)
	{
        /* Normalized result */
		exp = 2*x + 127;
		frac = 0;
	}
	else
	{
        /* Too big. Return +oo */
		exp = 255;
		frac = 0;
	}
	/* Pack exp and frac into 32 bytes */
	u = exp << 23 | frac;
	/* Return as float */
	return u2f(u);
}