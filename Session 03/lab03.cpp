#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

struct node
{
    int tableNo;
    char nameUser[12];
    char foodName[12];
    int qty;
    struct node *next;
};
struct node *start = NULL;
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *delete_beg(struct node *);

void init()
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->nameUser, "Dhea");
    strcpy(new_node->foodName, "Seblak");
    new_node->tableNo = 13;
    new_node->qty = 3;
    new_node->next = start;
    start = new_node;
}

int main()
{
    int menu = 0;
    init();

    while (1)
    {
        system("cls");
        printf("\nCAYNIS FOOD RESTAURANT\n#########################\n");
        printf("\n1. Order List \n2. Add Order \n3. Take Order \n4. Exit \n");

        if (menu == 99)
        {
            printf("\nWrong selection!!! Please try again!!!\n>> Input Choice : ");
        }
        else
        {
            printf("\n>> Input Choice : ");
        }

        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            system("cls");
            start = display(start);
            getch();
            break;
        case 2:
            system("cls");
            start = insert_beg(start);
            getch();
            break;
        case 3:
            system("cls");
            start = delete_beg(start);
            getch();
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

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    printf("\n %50s \n\n", "--- Order Caynis Food ---");
    printf("+----+--------------+-------------------------+-----------------+----------+\n");
    printf("| %2s | %-10s | %-23s | %-15s | %8s |\n", "No", "Table Number", "Customer Name", "Food", "Quantity");
    printf("+----+--------------+-------------------------+-----------------+----------+\n");
    int i = 1;
    while (ptr != NULL)
    {
        printf("| %2d | %-12d | %-23s | %-15s | %8d |\n", i++, ptr->tableNo, ptr->nameUser, ptr->foodName, ptr->qty);
        ptr = ptr->next;
    }
    printf("+----+--------------+-------------------------+-----------------+----------+\n");
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;

    ptr = start;
    if (ptr == NULL)
    {
        printf("There Are No Order Available.");
        return start;
    }
    start = start->next;
    free(ptr);
    printf("Order Has Been Delivered to Table.");
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *ptr, *new_node;
    char nameUsr[12], nameFood[12];
    int tableNoD, a, b, c, qtyD;
    do
    {
        printf("\nInput Table Number[1..20]: ");
        scanf("%d", &tableNoD);
    } while (tableNoD >= 19 && tableNoD <= 0);
    do
    {
        printf("\nInput Customer Name: ");
        scanf("%s", nameUsr);
        a = strlen(nameUsr);
    } while (a >= 19 || a <= 2);
    do
    {
        printf("\nInput Food Name[5..20]: ");
        scanf("%s", nameFood);
        b = strlen(nameFood);
    } while (b >= 19 || b <= 3);
    do
    {
        printf("\nInput Quantity[1..1000]: ");
        scanf("%d", &qtyD);
    } while (qtyD >= 1000 && qtyD <= 0);

    new_node = (struct node *)malloc(sizeof(struct node));

    if (start != NULL)
    {
        strcpy(new_node->nameUser, nameUsr);
        strcpy(new_node->foodName, nameFood);
        new_node->tableNo = tableNoD;
        new_node->qty = qtyD;
        new_node->next = NULL;
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
        printf("\n\n--- Add New Order Success ---\n");
    }
    else
    {
        strcpy(new_node->nameUser, nameUsr);
        strcpy(new_node->foodName, nameFood);
        new_node->tableNo = tableNoD;
        new_node->qty = qtyD;
        new_node->next = start;
        start = new_node;
        printf("\n\n--- Add New Order Success ---\n");
    }

    return start;
}