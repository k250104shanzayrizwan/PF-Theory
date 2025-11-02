#include <stdio.h>

int main()
{
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int bookCount = 0;
    int choice;
    int searchIsbn;
    int copiesSold;
    int found;
    int copy=0;

    while (1)
    {
        // --- Menu ---
        printf("\n---- Inventory Management System ----\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            if (bookCount >= 100)
            {
                printf("Inventory full! Cannot add more books.\n");
                break;
            }

            printf("Enter ISBN number: ");
            scanf("%d", &isbns[bookCount]);

        
            for (int i = 0; i < bookCount; i++)
            {
                if (isbns[i] == isbns[bookCount])
                {
                    copy = 1;
                    break;
                }
            }
            if (copy)
            {
                printf("Book with this ISBN already exists!\n");
                break;
            }

            printf("Enter Title: ");
            scanf("%s", titles[bookCount]);

            printf("Enter Price: ");
            scanf("%f", &prices[bookCount]);

            printf("Enter Quantity: ");
            scanf("%d", &quantities[bookCount]);

            bookCount++;
            printf("Book added successfully!\n");
            break;

        case 2:
            if (bookCount == 0)
            {
                printf("No books in inventory!\n");
                break;
            }

            printf("Enter ISBN to process sale: ");
            scanf("%d", &searchIsbn);

            found = 0;
            for (int i = 0; i < bookCount; i++)
            {
                if (isbns[i] == searchIsbn)
                {
                    found = 1;
                    printf("Enter number of copies sold: ");
                    scanf("%d", &copiesSold);

                    if (quantities[i] >= copiesSold)
                    {
                        quantities[i] -= copiesSold;
                        printf("Sale processed! Remaining quantity: %d\n", quantities[i]);
                    }
                    else
                    {
                        printf("Error: Not enough stock available.\n");
                    }
                    break;
                }
            }

            if (!found)
                printf("Book with ISBN %d not found.\n", searchIsbn);
            break;

        case 3:
            if (bookCount == 0)
            {
                printf("No books in inventory!\n");
                break;
            }

            printf("\n--- Low Stock Report (Quantity < 5) ---\n");
            found = 0;
            for (int i = 0; i < bookCount; i++)
            {
                if (quantities[i] < 5)
                {
                    found = 1;
                    printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                           isbns[i], titles[i], prices[i], quantities[i]);
                }
            }
            if (!found)
                printf("No low-stock books found.\n");
            break;

        case 4:
            printf("Exiting program. Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
