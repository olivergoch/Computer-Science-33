#include <stdio.h>
#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    int result = (int) ux + uy;
    int shifting = (sizeof(int) << 3) - 1;
    (__builtin_add_overflow(x, y, &result)) && !(x>>shifting & 1) && !(y>>shifting & 1) && (result = INT_MAX);
    (__builtin_add_overflow(x, y, &result)) && (x>> shifting & 1) && (y>> shifting & 1) && (result = INT_MIN);
    return result;
}