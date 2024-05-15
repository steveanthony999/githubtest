/* Section 1.8: Arguments - Call by Value */

/*
 * C function parameters are local variables to that function.
 * The arguments passed into them are not affected.
 * This is known as pass by value.
 * It is, however, different for arrays.  The value passed to
   the function is the address of the beginning of the array,
   there is no copying of the array elements.  By subscripting
   this value, the function can access and alter any argument
   of the array.
*/
#include <stdio.h>

int pass_num(int n);

int main() {
    int num = 10;

    printf("original num: %d\taltered num: %d\t original num again: %d\n", num, pass_num(num), num);

    return 0;
}

int pass_num(int n) {
    n = 20;
    return n;
}

















