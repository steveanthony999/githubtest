#include <stdio.h>

/* 
    CH 1
    Section 1.6
    Arrays
*/

/* Count the number of occurences of each digit, of white space characters (blank, tab, newline), and of all other characters */
/* int main() {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf("%d", ndigit[i]);
    }

    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}
*/

/* Exercise 1-13: Write a program to print a histogram of the lengths of words in it's input. */
#define IN   1
#define OUT  0

/*
int main() {
    int c, i, nchars, state;

    nchars = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                printf("%3d", nchars);
                for (i = 0; i < nchars; ++i) {
                    printf("|");
                }
                putchar('\n');
                nchars = 0;
                state = OUT;
            }
        } else {
            ++nchars;
            if (state == OUT) {
                state = IN;
            }
            putchar(c);
        }
    }
    return 0;
}
*/

// variation
/* #define MAX_LENGTH 20
int main() {
    int c, i, j, state, nchars;
    int word_lengths[MAX_LENGTH+1];

    // Initialize the word lengths array to 0
    for (i = 0; i < MAX_LENGTH+1; ++i)
        word_lengths[i] = 0;

    state = OUT;
    nchars = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                state = OUT;
                if (nchars < MAX_LENGTH)
                    ++word_lengths[nchars-1];
                else
                    ++word_lengths[MAX_LENGTH];
            }
            nchars = 0;
        } else {
            ++nchars;
            if (state == OUT)
                state = IN;
        }

    // Print the histogram
    for (i = 1; i < MAX_LENGTH; ++i) {
        printf("%4d: ", i);
        for (j = 0; j < word_lengths[i]; ++j) {
            putchar('|');
        }
        putchar('\n');
    }

    return 0;
}
*/

// Exercise 1-14: Write a program to print a histogram of the frequencies of different characters in it's input.
//
// Print the character
// Get the ASCII value for the character
// Get a character count for the letter 'a'
// Get a count for each character used
#define ARR_SIZE    256
int main() {
    int c, i, j, nchars, char_array[ARR_SIZE];
    
    nchars = 0;

    for (i = 0; i < ARR_SIZE; ++i) {
        char_array[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < ARR_SIZE) {
            ++char_array[c];
        }
    }

    for (i = 0; i < ARR_SIZE; ++i) {
        if (char_array[i] > 0) {
            if (i > 32 && i <= 128) {
                printf("%c: ", i);
                for (j = 0; j < char_array[i]; ++j) {
                    putchar('|');
                }
                putchar('\n');
            } else {
                printf("ASCII %d: ", i);
                for (j = 0; j < char_array[i]; ++j) {
                    putchar('|');
                }
                putchar('\n');
            }
        }
    }

    return 0;
}

























