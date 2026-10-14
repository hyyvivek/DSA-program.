
#include <stdio.h>

int main()
{
    int choice, quantity;
    int total = 0;
    char more;

    do
    {
        printf("\n================================\n");
        printf("     FOOD ORDER MANAGEMENT\n");
        printf("================================\n");
        printf("1. Pizza       - Rs. 200\n");
        printf("2. Burger      - Rs. 100\n");
        printf("3. Sandwich    - Rs. 80\n");
        printf("4. French Fries- Rs. 70\n");
        printf("5. Cold Drink  - Rs. 50\n");
        printf("6. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6)
        {
            break;
        }

        if (choice < 1 || choice > 5)
        {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        if (scanf("%d", &quantity) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        if (quantity <= 0)
        {
            printf("Quantity must be greater than zero.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                total += 200 * quantity;
                printf("Pizza added to your order.\n");
                break;

            case 2:
                total += 100 * quantity;
                printf("Burger added to your order.\n");
                break;

            case 3:
                total += 80 * quantity;
                printf("Sandwich added to your order.\n");
                break;

            case 4:
                total += 70 * quantity;
                printf("French Fries added to your order.\n");
                break;

            case 5:
                total += 50 * quantity;
                printf("Cold Drink added to your order.\n");
                break;
        }

        printf("Do you want to order more? (y/n): ");
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');

    printf("\n================================\n");
    printf("          FINAL BILL\n");
    printf("================================\n");
    printf("Total Amount: Rs. %d\n", total);
    printf("Thank you for ordering!\n");
    printf("================================\n");

    return 0;
}
