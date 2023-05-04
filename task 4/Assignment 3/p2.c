#include <stdio.h>

#define ADD(x, y) (x + y)
#define SUBTRACT(x, y) (x - y)

#define ADD_OPERATION 1
#define SUBTRACT_OPERATION 2

int main() {
    int operand1, operand2, result;
    int operation;

    printf("Enter operand1, operand2, and operation (1 for add, 2 for subtract):\n");
    scanf("%d %d %d", &operand1, &operand2, &operation);

    switch(operation) {
        case ADD_OPERATION:
            result = ADD(operand1, operand2);
            break;
        case SUBTRACT_OPERATION:
            result = SUBTRACT(operand1, operand2);
            break;
        default:
            printf("Error: Invalid operation.\n");
            return 1;
    }

    printf("%d %s %d = %d\n", operand1, operation == ADD_OPERATION ? "+" : "-", operand2, result);

    return 0;
}