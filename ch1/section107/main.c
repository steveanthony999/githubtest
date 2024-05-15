/* Section 1.7 - Functions */

#include <stdio.h>

/* power function example */

/* int power(int m, int n);

int main() {
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
    return 0;
} */

/* power: raise base to the n-th power; n >= 0 */
/* int power(int base, int n) {
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
*/

/* Exercise 1.15: Rewrite the temperature conversion program of section 1.2 to use a function for conversion. */

float fahr_to_celc(int f);
int celc_to_fahr(float c);

int main() {
    int i;
    float j;

    for (i = 0; i <= 120; i = i + 30) {
        printf("fahr: %4d\tcelc: %6.2f\n", i, fahr_to_celc(i));
    }

    for (j = 50.0; j >= -20.0; j = j - 10.0) {
        printf("celc: %6.2f\tfahr: %4d\n", j, celc_to_fahr(j));
    }

    return 0;
}

float fahr_to_celc(int f) {
    float c;

    c = (f - 32.0) * (5.0 / 9.0);
    
    return c;
}

int celc_to_fahr(float c) {
    int f;

    f = (c * 9 / 5) + 32;

    return f;
}





















