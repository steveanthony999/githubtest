#include <stdio.h>

/* int main() {
	int c;

	c = getchar();
	while(c != EOF) {
		putchar(c);
		c = getchar();
	}

	return 0;
} */

// Copy input to output, 2nd version
/* int main() {
	int c;
	while((c = getchar()) != EOF) { // Gets a character, assigns it to c, then tests whether the character was the end-of-file signal
		putchar(c); // Prints the character
	}

	return 0;
} */

// Exercise 1.6: Verify that the expression getchar() != EOF is 0 or 1
/* int main() {
    int c;
    while ((c = getchar()) != EOF) {
        printf("Is 0 or 1? %d\n", c != EOF);
    }

    printf("Is 0 or 1? %d\n", c != EOF);
    return 0;
}
*/

// Exercise 1.7: Write a program to print the value of EOF
/* int main() {
    printf("%d\n", EOF);
    return 0;
}
*/

/* int main() {
	long nc;
	nc = 0;

	while(getchar() != EOF) {
		++nc;
		printf("%ld\n", nc);
	}

	return 0;
} */

/* int main() {
	double nc;
	
	for(nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);

	return 0;
} */

// Section 1.5.3 - Line Counting
// Counts input lines

/* int main() {
	int c, nl;

	nl = 0;
	printf("Count Input Lines\n");
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);

	return 0;
} 
*/

// Exercise 1-8: Write a program to count blanks

/* int main() {
	int c, blank;
	blank = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ')
			++blank;
	printf("%d\n", blank);
	return 0;
}
*/

// Exercise 1-8: Write a program to count tabs

/* int main() {
    int c, t;
    t = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            ++t;
    }
    printf("The number of tabs were %d\n", t);
    return 0;
}
*/

// Exercise 1-8: Write a program to count newlines
/* int main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("The number of new lines are %d\n", nl);
}
*/

// Exercise 1-8: Write a program to count blanks, tabs, and newlines
/* int main() {
    int c, blanks, tabs, newlines;
    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
    }

    printf("\tBlanks: %d\n\tTabs: %d\n\tNew Lines: %d\n", blanks, tabs, newlines);

    return 0;
}
*/

// Exercise 1-9: Write a program to copy it's input to it's output, replacing each string of one or more blanks by a single blank
/* int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            c = '\0';
        }
        putchar(c);
    }

    return 0;
}
*/

// Exercise 1-10: Write a program to copy it's input to it's output, replacing each tab by \t, each backspace by \b, and each backslash by \\.
// This makes tabs and backspaces visible in an unambiguous way
/* int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            c = 't';
        }

        if (c == '\\') {
            putchar('\\');
            c = '\\';
        }

        putchar(c);
    }

    return 0;
}
*/


// Section 1.5.4 - Word Counting

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
/* int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
*/

// How would you test the word count problem?
// Basic cases:        Simple sentences.
//                     Single words.
//                     Empty inputs.
// Boundary cases:     Multiple spaces.
//                     Multiple newlines.
//                     Tabs.
// Edge cases:         Input ending with spaces.
//                     Input ending with newline.
//                     Input of only spaces, tabs, and newlines.
// Complex cases:      Mixed punctuation.
//                     Long input.
// Special characters: Non-alphabetic
//                     Special symbols
// Stress test:        Large input

// What kinds of inputs are most likely to uncover bugs if there are any?
// State transitions

// Write a program that prints it's input one word per line.
/* int main() {
    int c, state;
    
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
           state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            putchar('\n');
        }
        putchar(c);
    }

    return 0;
}
*/

// Variation
int main() {
    int c, state;
    
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (state == IN) {
                putchar('\\');
                putchar('n');
                putchar('\n');
                state = OUT;
            }
        } else {
            if (state == OUT) {
                state = IN;
            }
            putchar(c);
        }
    }
    return 0;
}

















