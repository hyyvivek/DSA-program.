
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Passenger
{
    int ticketNo;
    char name[50];
    int age;
    char source[30];
    char destination[30];
};

struct Passenger p[MAX];
int count = 0;
int nextTicket = 1001;

void bookTicket()
{
    if (count >= MAX)
    {
        printf("\nReservation list is full!\n");
        return;
    }

    p[count].ticketNo = nextTicket++;

    printf("\nEnter passenger name: ");
    scanf(" %49[^\n]", p[count].name);

    printf("Enter age: ");
    scanf("%d", &p[count].age);

    printf("Enter source station: ");
    scanf(" %29[^\n]", p[count].source);

    printf("Enter destination station: ");
    scanf(" %29[^\n]", p[count].destination);

    printf("\nTicket booked successfully!\n");
    printf("Your Ticket Number: %d\n", p[count].ticketNo);

    count++;
}

void viewTickets()
{
    int i;

    if (count == 0)
    {
        printf("\nNo reservations found!\n");
        return;
    }

    printf("\n--- Reserved Tickets ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nTicket Number: %d\n", p[i].ticketNo);
        printf("Passenger Name: %s\n", p[i].name);
        printf("Age: %d\n", p[i].age);
        printf("Source: %s\n", p[i].source);
        printf("Destination: %s\n", p[i].destination);
    }
}

void cancelTicket()
{
    int ticket, i, j;

    printf("\nEnter ticket number to cancel: ");
    scanf("%d", &ticket);

    for (i = 0; i < count; i++)
    {
        if (p[i].ticketNo == ticket)
        {
            for (j = i; j < count - 1; j++)
            {
                p[j] = p[j + 1];
            }

            count--;
            printf("\nTicket cancelled successfully!\n");
            return;
        }
    }

    printf("\nTicket number not found!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== RAILWAY RESERVATION SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. View Reservations\n");
        printf("3. Cancel Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                bookTicket();
                break;

            case 2:
                viewTickets();
                break;

            case 3:
                cancelTicket();
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
