#include <stdio.h>

int main() {
	float fahr, celc;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	printf("Fahrenheit to Celcius Looper");
	while(fahr <= upper) {
		celc = (5.0/9.0) * (fahr - 32.0);	
		printf("%3.0f\t%6.2f\n", fahr, celc);
		fahr = fahr + step;
	}

	celc = lower;
	printf("Celcius to Fahrenheit Looper");
	while(celc <= upper) {
		fahr = (celc * 9/5) + 32;
		printf("%3.0f\t%6.2f\n", celc, fahr);
		celc = celc + step;
	}

	return 0;
}

