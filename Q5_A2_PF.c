#include <stdio.h>
#include <string.h>

// Function to toggle 2nd and 5th bits
char toggleBits(char ch)
{
    return ch ^ 0b00010010; // same as XOR 18
}

void Encoding(char str[])
{
    int i = 0, length = strlen(str);
    char rev[5000], encoded[5000];

    // Remove newline if present (from fgets)
    if (str[length - 1] == '\n')
        str[--length] = '\0';

    // Step 1: Reverse the string
    for (i = 0; i < length; i++)
    {
        rev[i] = str[length - 1 - i];
    }
    rev[length] = '\0';

    // Step 2: Toggle 2nd and 5th bits
    for (i = 0; i < length; i++)
    {
        encoded[i] = toggleBits(rev[i]);
    }
    encoded[length] = '\0';

    printf("\nThe encoded string is: %s\n\n", encoded);
}

void Decoding(char str[])
{
    int i = 0, length = strlen(str);
    char toggled[5000], decoded[5000];

    if (str[length - 1] == '\n')
        str[--length] = '\0';

    // Step 1: Toggle bits back (reversible)
    for (i = 0; i < length; i++)
    {
        toggled[i] = toggleBits(str[i]);
    }
    toggled[length] = '\0';

    // Step 2: Reverse again to original
    for (i = 0; i < length; i++)
    {
        decoded[i] = toggled[length - 1 - i];
    }
    decoded[length] = '\0';

    printf("\nThe decoded string is: %s\n\n", decoded);
}

int main()
{
    char message[5000];
    int choice = 0;

    while (choice != 3)
    {
        printf("Menu for Encoding and Decoding System!\n");
        printf("1. Encoding\n2. Decoding\n3. Exit\nEnter Number: ");
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf

        switch (choice)
        {
        case 1:
            printf("Enter message to be encoded: ");
            fgets(message, sizeof(message), stdin);
            Encoding(message);
            break;

        case 2:
            printf("Enter message to be decoded: ");
            fgets(message, sizeof(message), stdin);
            Decoding(message);
            break;

        case 3:
            printf("Program Exited!\n");
            break;

        default:
            printf("Invalid Input!\n");
            break;
        }
    }

    return 0;
}
