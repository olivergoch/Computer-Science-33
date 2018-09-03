#include <stdio.h>
/*A: %rdi & %r8 hold x, %ecx & %esi holds n, %eax & %rax hold result, and %edx & %rdx hold mask*/

/*B: result is initially 0, mask is initially undeclared before having the value of 1 in the initialization portion of the for loop*/

/*C: the test condition of the for loop is if mask is not eqaul to 0, meaning if that mask is equal to 0 it will exit the loop*/

/*D: Mask is left shifted by n*/

/*E: Result is ORed with the AND of x and mask*/

/*F:*/
long loop(long x, long n)
{
    long result = 0;
    long mask;
    for(mask = 1; mask != 0; mask = mask << n)
        result |= (x&mask);
    return result;
}