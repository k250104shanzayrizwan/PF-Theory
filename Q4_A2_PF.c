
#include <stdio.h>
int push(int stack[], int top, int maxsize)
{
    if (top <= maxsize - 1)
    {
        top++;
        printf("Enter integer to be added in the stack: ");
        scanf("%d", &stack[top]);
        printf("Element added sucessfully!\n");
    }
    else
    {
        printf("The Stack is full!\n");
    }
    return top;
}
int pop(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty, Nothing popped!\n");
    }
    else
    {
        printf("The popped item is %d.\n", stack[top]);
        top--;
    }
    return top;
}
void peek(int stack[], int top)
{
    printf("The top element in stack is %d.\n", stack[top]);
}
void display(int stack[], int top)
{
    int i = 0;
    printf("%4s \t %7s\n", "S.No", "Element\n");
    for (i = -1; i <= top; i++)
    {
        if (i == -1)
            continue;
        printf("%4d \t %7d\n", i + 1, stack[i]);
    }
}
int main()
{
    const int null = -1;
    int top = null;
    int maxsize = 10;
    int stack[maxsize];
    int num = 0;
    while (num != 5)
    {
        printf("Choose From Menu:\n1. Add Item in Stack\n2. Remove Item From Stack\n3. Last Element in Stack\n4. Display Stack\n5. Exit Program\nEnter Number: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            top = push(stack, top, maxsize);
            break;
        case 2:
            top = pop(stack, top);
            break;
        case 3:
            peek(stack, top);
            break;
        case 4:
            display(stack, top);
            break;
        case 5:
            printf("Program Exit!\n");
            break;
        default:
            printf("Invalid Input!\n");
            break;
        }
    }
    return 0;
}