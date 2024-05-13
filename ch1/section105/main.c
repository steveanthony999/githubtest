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

int main() {
	long nc;
	nc = 0;

	while(getchar() != EOF) {
		++nc;
		printf("%ld\n", nc);
	}

	return 0;
} 














