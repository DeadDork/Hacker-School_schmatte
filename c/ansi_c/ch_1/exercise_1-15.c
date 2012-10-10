#include <stdio.h>

// Function prototype.
float convert(int m);

// Prints out the celsius values from 0 Fahrenheit - 300 Fahrenheit.
int main() {
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
		printf("%3d %6.1f\n", fahr, convert(fahr));
	}

	return 0;
}

// Uses the conversion: Celsius = (5/9) * Fahrenheit - 32.
float convert(int fahr) {
	float cels = ((5.0 / 9.0) * fahr - 32);

	return cels;
}
