#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct food
{
    char customerName[30];
    char foodName[30];
    char customerAddress[30];
    struct food *next;
    struct food *prev;
} * start, *end, *current;

int data = 0;

void printMenu()
{
    printf("ACE FOOD DELIVERY\n");
    printf("--------------------\n\n");
    printf("1. View Order List\n");
    printf("2. Add New Order\n");
    printf("3. Take Order\n");
    printf("4. Exit\n\n");
}

void push(char name[], char foodorder[], char alamat[])
{
    struct food *ptr;
    current = (struct food *)malloc(sizeof(food));
    strcpy(current->customerName, name);
    strcpy(current->foodName, foodorder);
    strcpy(current->customerAddress, alamat);

    if (start == NULL)
    {
        start = current;
        current->next = start;
        current->prev = start;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = current;
        start->prev = ptr;
        current->next = start;
        current->prev = ptr;
    }
}

void pop(int take)
{
    int u, i;
    u = 1;
    struct food *ptr;
    struct food *temp;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
        u++;
    }
    if (take == 1)
    {
        ptr = start;
        do
        {
            ptr = ptr->next;
        } while (ptr->next != start);
        temp = ptr->next;
        ptr->next = start->next;
        start->next->prev = ptr;
        start = start->next;
        free(temp);
    }
    else if (take == u)
    {
        ptr = start;
        while (ptr->next->next != start)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        ptr = start->prev;
    }
    else
    {
        ptr = start;
        for (i = 1; i < take - 1; i++)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
    }
}

void viewOrder()
{
    printf("\n\n                       --- ACE FOOD DELIVERY ORDER LIST ---              \n\n");
    printf("+-----+--------------------------+-----------------------------+-----------------------------+\n");
    printf("| No. |  Customer Name  	 |  Food Order                 |  Delivery Address  	     |\n");
    printf("+-----+--------------------------+-----------------------------+-----------------------------+\n");

    if (data == 0)
    {
        printf("|                               ORDER LIST IS EMPTY                                          |\n");
    }
    else
    {
        int i = 1;
        struct food *n;
        n = start;
        do
        {
            if (current != NULL)
            {
                printf("| %d.  | %-25s| %-27s | %-27s |\n", i, n->customerName, n->foodName, n->customerAddress);
                n = n->next;
                i++;
            }
        } while (n != start);
    }

    printf("+-----+--------------------------+-----------------------------+-----------------------------+\n");
}

void addOrder()
{
    char name[30], foodorder[30], alamat[30];

    do
    {
        printf("\nInput Customer Name [3..30]: ");
        fflush(stdin);
        scanf("%[^\n]", &name);
    } while (strlen(name) < 3 || strlen(name) > 30);

    do
    {
        printf("\nInput Food Order [3..30]: ");
        fflush(stdin);
        scanf("%[^\n]", &foodorder);
    } while (strlen(foodorder) < 3 || strlen(foodorder) > 20);

    do
    {
        printf("\nInput Delivery Address [6 . . . . 30]: ");
        fflush(stdin);
        scanf("%[^\n]", &alamat);
    } while (strlen(alamat) < 6 || strlen(alamat) > 30);

    printf("\n\n--- Add New Order Success ---");
    data++;

    push(name, foodorder, alamat);
}

void takeOrder()
{
    int hapus = 0;

    if (data != 0)
    {
        do
        {
            printf("\n\nInput Number of Order [1...%d] : ", data);
            scanf("%d", &hapus);
        } while (hapus < 1 || hapus > data);

        if (data == 1)
        {
            free(start);
            printf("\n\n--- Take an Order Success ---");
            getch();
        }
        else
        {
            pop(hapus);
            printf("\n\n--- Take an Order Success ---");
            getch();
        }
        data--;
        return;
    }
    printf("\n--- There is No Order in The List  ---");
    getch();
}

int main()
{
    int menu = 0;

    while (1)
    {
        system("cls");
        printMenu();

        if (menu == 99)
        {
            printf("Wrong selection!!! Please try again!!!\n>> Input Choice : ");
        }
        else
        {
            printf(">> Input Choice : ");
        }

        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            system("cls");
            viewOrder();
            getch();
            break;
        case 2:
            system("cls");
            addOrder();
            getch();
            break;
        case 3:
            system("cls");
            viewOrder();
            takeOrder();
            break;
        case 4:
            exit(0);
            break;
        default:
            menu = 99;
        }
    }

    return 0;
}