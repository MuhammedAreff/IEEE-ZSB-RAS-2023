#include <stdio.h>

typedef struct {
    float real;
    float imag;
} complex;

complex add_complex(complex num1, complex num2) {
    complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

int main() {
    complex num1, num2, result;

    printf("Enter real and imaginary parts of first complex number:\n");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter real and imaginary parts of second complex number:\n");
    scanf("%f %f", &num2.real, &num2.imag);

    result = add_complex(num1, num2);

    printf("Sum = %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}