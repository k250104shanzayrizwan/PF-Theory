#include <stdio.h>

void update(int arr[10][10])
{
    printf("\n");
    int inp, row, col;
    printf("Enter row in range of 1 to 10: ");
    scanf("%d", &row);
    while (row < 1 || row > 10)
    {
        printf("Enter row again in range of 1 to 10: ");
        scanf("%d", &row);
    }
    printf("Enter col in range of 1 to 10: ");
    scanf("%d", &col);
    while (col < 1 || col > 10)
    {
        printf("Enter column again in range of 1 to 10: ");
        scanf("%d", &col);
    }
    printf("Enter Num in range of 0 to 7: ");
    scanf("%d", &inp);
    while (inp < 0 || inp > 7)
    {
        printf("Enter Num again in range of 0 to 7: ");
        scanf("%d", &inp);
    }
    arr[row - 1][col - 1] = inp;
    printf("\n");
}

void query(int arr[10][10])
{
    printf("\n");
    int row, col;
    printf("Enter row in range of 1 to 10: ");
    scanf("%d", &row);
    while (row < 1 || row > 10)
    {
        printf("Enter row again in range of 1 to 10: ");
        scanf("%d", &row);
    }

    printf("Enter col in range of 1 to 10: ");
    scanf("%d", &col);
    while (col < 1 || col > 10)
    {
        printf("Enter column again in range of 1 to 10: ");
        scanf("%d", &col);
    }

    if (arr[row - 1][col - 1] == 16)
        printf("\nThis sector has not been initialized yet!\n\n");
    else
    {
        printf("\nReport\n");

        if (arr[row - 1][col - 1] & 1)
            printf("The Power Status is On!\n");
        else
            printf("The Power Status is Off!\n");

        if (arr[row - 1][col - 1] & 2)
            printf("There's an Overload Warning!\n");
        else
            printf("There's no Overload Warning!\n");

        if (arr[row - 1][col - 1] & 4)
            printf("Maintenance required!\n");
        else
            printf("No Maintenance required!\n");
        printf("\n");
    }
}

void diagnostic(int arr[10][10])
{
    int i, j, number = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if ((arr[i][j] & 2) || (arr[i][j] & 4))
                number++;
        }
    }
    printf("\nThe number of sectors that are currently overloaded or requiring maintenance are %d.\n\n", number);
}

int main()
{
    int i, j, grid[10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            grid[i][j] = 16;
    }
    int choice = 0;
    while (choice != 4)
    {
        printf("Choose From Menu:\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostics\n");
        printf("4. Exit Program\n");
        printf("Enter Number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            update(grid);
            break;
        case 2:
            query(grid);
            break;
        case 3:
            diagnostic(grid);
            break;
        case 4:
            printf("Program Exited!\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
