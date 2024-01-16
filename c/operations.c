#include <stdio.h>

int main(void)
{
    int x, y, operation, result;

    printf("Pick an operation:\n");
    printf("1. Sum\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &operation);

    printf("Type a number: ");
    scanf("%d", &x);
    printf("Type another number: ");
    scanf("%d", &y);

    switch (operation)
    {
    case 1:
        result = x + y;
        printf("Result of the sum: %d\n", result);
        break;
    case 2:
        result = x - y;
        printf("Result of the subtraction: %d\n", result);
        break;
    case 3:
        result = x * y;
        printf("Result of the multiplication: %d\n", result);
        break;
    case 4:
        if (y != 0)
        {
            result = x / y;
            printf("Result of the division: %d\n", result);
        }
        else
        {
            printf("Error: Division by zero is not allowed.\n");
        }
        break;
    default:
        printf("Invalid operation\n");
        break;
    }

    return 0;
}
