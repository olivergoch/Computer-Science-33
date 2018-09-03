#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    int result = (int) ux + uy;
    int shifting = (sizeof(int) << 3) - 1;
    (result >> shifting & 1) && !(x>>shifting & 1) && !(y>>shifting & 1) && (result = INT_MAX);
    (~(result>> shifting) & 1) && (x>> shifting & 1) && (y>> shifting & 1) && (result = INT_MIN);
    return result;
}