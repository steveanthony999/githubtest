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

/* int main() {
	int c;
	printf("%d", EOF);
	while((c = getchar()) != EOF) {
		putchar(c);
	}

	return 0;
} */

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
int main() {
    int c, blanks, tabs, newlines;
    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;

    printf("\tBlanks: %d\n\tTabs: %d\n\tNew Lines: %d\n", blanks, tabs, newlines);

    return 0;
}







