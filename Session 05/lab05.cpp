#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct list
{
    int price;
    char nama[30];
    struct list *next;
    struct list *prev;
} * head, *tail, *node;

void PrintMenu()
{
    printf("BLUE TOYS SHOP\n");
    printf("............................\n\n");
    printf("1. View Order List\n");
    printf("2. Add New Order\n");
    printf("3. Take Order\n");
    printf("4. Exit\n\n");
}

void ViewOrder()
{
    if (head != NULL)
    {
        node = head;
        printf("\n %25s \n\n", "--- ITEM LIST ---");
        printf("+----+--------------------------+----------------------+\n");
        printf("| %2s | %-24s | %-20s |\n", "No", "Name of Toys", "Price");
        printf("+----+--------------------------+----------------------+\n");
        int i = 1;
        do
        {
            printf("| %-2d | %-24s | %-20d |\n", i++, node->nama, node->price);
            node = node->next;
        } while (node != head);
        printf("+----+--------------------------+----------------------+\n");
    }
    else
    {
        printf("\n %35s \n\n", "--- ITEM LIST ---");
        printf("+----+--------------------------+----------------------+\n");
        printf("| %2s | %-24s | %-20s |\n", "No", "Name of Toys", "Price");
        printf("+----+--------------------------+----------------------+\n");
        printf("| %30s %23s\n", "data is empty", "|");
        printf("+----+--------------------------+----------------------+\n");
    }
}

void AddOrder()
{
    char nama[30];
    int price;
    do
    {
        printf("\nInput Name of Toy [3..30] : ");
        scanf("%s", nama);
    } while (strlen(nama) >= 30 || strlen(nama) <= 3);
    do
    {
        printf("\nInput Price of Toy [1000...1000000]: ");
        scanf("%d", &price);
    } while (price <= 1000 && price >= 1000000);

    struct list *ptr;
    node = (struct list *)malloc(sizeof(list));
    node->price = price;
    strcpy(node->nama, nama);

    if (head == NULL)
    {
        head = node;
        node->next = head;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = node;
        node->next = head;
    }

    printf("\n\n\n--- Add New Order Success---");
    getch();
}

void delet(int take)
{
    int i, u;
    u = 1;
    struct list *ptr;
    struct list *temp;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        u++;
    }
    if (take == 1)
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = head->next;
        head = head->next;
        free(temp);
    }
    else if (take == u)
    {
        ptr = head;
        while (ptr->next->next != head)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    else
    {
        ptr = head;
        for (i = 1; i < take - 1; i++)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
}

void TakeOrder()
{
    int take;

    printf("\n\nInput Number of Order: ");
    scanf("%d", &take);
    delet(take);
}

int main()
{
    int menu = 0;

    while (1)
    {
        system("cls");
        PrintMenu();

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
            ViewOrder();
            getch();
            break;
        case 2:
            system("cls");
            AddOrder();
            break;
        case 3:
            system("cls");
            ViewOrder();
            TakeOrder();
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