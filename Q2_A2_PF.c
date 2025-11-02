#include <stdio.h>
#include <string.h>

void Customer_info(char name[], char CNIC[])
{
    printf("Enter the Name: ");
    scanf("%s", name);
    printf("Enter CNIC Number: ");
    scanf("%s", CNIC);
}

void displayInventory(int productCodes[], int quantities[], float prices[], int size)
{
    printf("\n------------------ Inventory List ------------------\n");
    printf("%-10s %-15s %-10s\n", "Code", "Quantity", "Price");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < size; i++)
    {
        printf("%-10d %-15d %-10.2f\n", productCodes[i], quantities[i], prices[i]);
    }
    printf("----------------------------------------------------\n");
}

void Update_Inventory(int quantities[], int index, int purchasedAmount)
{
    if (quantities[index] == 0)
    {
        printf("Out Of Stock\n");
    }
    else if (quantities[index] < 5)
    {
        printf("Low stock\n");
    }
    else
    {
        printf("Stock Is available\n");
    }

    quantities[index] = quantities[index] - purchasedAmount;
}

void Add_to_Cart(int productsCodes[], float prices[],
                 int quantities[], int cartCodes[], int cartQuantities[],
                 float cartPrices[], int numItems, int *cartCount)
{
    int code, units;
    int found = 0;

    printf("Enter the product code: ");
    scanf("%d", &code);

    printf("Enter the quantity: ");
    scanf("%d", &units);

    for (int i = 0; i < numItems; i++)
    {
        if (productsCodes[i] == code)
        {
            found = 1;

            if (quantities[i] >= units)
            {
                quantities[i] -= units;
                cartCodes[*cartCount] = productsCodes[i];
                cartQuantities[*cartCount] = units;
                cartPrices[*cartCount] = prices[i] * units;
                (*cartCount)++;

                printf("Product Found: Code %03d\n", productsCodes[i]);
                printf("Added to cart successfully! Total = %.2f\n", prices[i] * units);
            }
            else
            {
                printf("Product Found: Code %03d\n", productsCodes[i]);
                printf("Not enough stock available!\n");
            }
            break;
        }
    }
    if (!found)
    {
        printf("Product with code %d not found.\n", code);
    }
}

float display_Bill(float cartPrices[], int numItems)
{
    int i;
    char promoCode[20];
    float total = 0;

    for (i = 0; i < numItems; i++)
        total += cartPrices[i];

    printf("Do you have a promo code (Eid2025)? ");
    scanf("%s", promoCode);

    if (strcmp(promoCode, "Eid2025") == 0)
    {
        total = total * 0.75;
        printf("Final Bill Amount (25%% off): %.2f\n", total);
    }
    else
    {
        printf("Total Bill: %.2f\n", total);
    }

    return total;
}

void show_Invoice(char name[],
                  char CNIC[],
                  int cartCodes[],
                  int cartQuantities[],
                  float cartPrices[],
                  float Total_bill,
                  int numItems)
{
    printf("\n--------------- Invoice ---------------\n");
    printf("Customer Name : %s\n", name);
    printf("Customer CNIC : %s\n", CNIC);
    printf("---------------------------------------\n");
    printf("%-10s %-10s %-10s\n", "Code", "Qty", "Price");
    printf("---------------------------------------\n");

    for (int i = 0; i < numItems; i++)
    {
        printf("%-10d %-10d %-10.2f\n", cartCodes[i], cartQuantities[i], cartPrices[i]);
    }

    printf("---------------------------------------\n");
    printf("Total Bill : %.2f\n", Total_bill);
    printf("=======================================\n");
    printf("   Thank you for shopping!\n");
    printf("=======================================\n");
}

int main()
{
    int productsCodes[] = {1, 2, 3, 4};
    float prices[] = {100, 200, 300, 150};
    int quantities[] = {50, 10, 20, 8};
    int choice;
    int cartCodes[100], cartQuantities[100];
    float cartPrices[100];
    int cartCount = 0;
    char name[50], CNIC[20];
    float total = 0;
    int numItems = 4; // only 4 items available

    while (1)
    {
        printf("\n---------- MENU ----------\n");
        printf("1. Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item To Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Customer_info(name, CNIC);
            break;

        case 2:
            displayInventory(productsCodes, quantities, prices, numItems);
            break;

        case 3:
            Add_to_Cart(productsCodes, prices, quantities, cartCodes, cartQuantities, cartPrices, numItems, &cartCount);
            break;

        case 4:
            total = display_Bill(cartPrices, cartCount);
            break;

        case 5:
            show_Invoice(name, CNIC, cartCodes, cartQuantities, cartPrices, total, cartCount);
            break;

        case 6:
            printf("Exiting system...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
