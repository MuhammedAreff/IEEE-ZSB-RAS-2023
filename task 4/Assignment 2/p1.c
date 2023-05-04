#include <stdio.h>

enum arithmetic_op {
    ADD = '+',
    SUBTRACT = '-',
    MULTIPLY = '*',
    DIVIDE = '/',
    AND = '&',
    OR = '|',
    NOT = '!'
};

int main() {
    float operand1, operand2, result;
    char operation;

    printf("Enter operand1, operand2, and operation (+, -, *, /, &, |, !):\n");
    scanf("%f %f %c", &operand1, &operand2, &operation);

    switch(operation) {
        case ADD:
            result = operand1 + operand2;
            break;
        case SUBTRACT:
            result = operand1 - operand2;
            break;
        case MULTIPLY:
            result = operand1 * operand2;
            break;
        case DIVIDE:
            result = operand1 / operand2;
            break;
        case AND:
            result = (int)operand1 & (int)operand2;
            break;
        case OR:
            result = (int)operand1 | (int)operand2;
            break;
        case NOT:
            result = !(int)operand1;
            break;
        default:
            printf("Error: Invalid operation.\n");
            return 1;
    }

    printf("%.2f %c %.2f = %.2f\n", operand1, operation, operand2, result);

    return 0;
}