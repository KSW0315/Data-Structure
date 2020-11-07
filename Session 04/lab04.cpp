#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node
{
    int qty;
    int price;
    char name[30];
    char type[30];
    struct Node *next, *prev;
} * head, *tail, *current;

void printMenu()
{
    printf("COOL COMPUTER ADMINISTRATOR\n");
    printf("---------------------------\n\n");
    printf("1. Item List\n");
    printf("2. Add <PUSH> New Item\n");
    printf("3. Delete <POP> Recently Added Item\n");
    printf("4. Exit\n\n");
}

void showlist()
{
    if (head != NULL)
    {
        current = head;
        printf("\n %45s \n\n", "--- ITEM LIST ---");
        printf("+----+--------------------------+----------------------+----------+-------+\n");
        printf("| %2s | %-24s | %-20s | %8s | %5s |\n", "No", "Name", "Type", "Quantity", "Price");
        printf("+----+--------------------------+----------------------+----------+-------+\n");
        int i = 1;
        while (current != NULL)
        {
            printf("| %-2d | %-24s | %-20s | %8d | $ %-3d |\n", i++, current->name, current->type, current->qty, current->price);
            current = current->next;
        }
        printf("+----+--------------------------+----------------------+----------+-------+\n");
    }
    else
    {
        printf("\n %45s \n\n", "--- ITEM LIST ---");
        printf("+----+--------------------------+----------------------+----------+-------+\n");
        printf("| %2s | %-24s | %-20s | %8s | %5s |\n", "No", "Name", "Type", "Quantity", "Price");
        printf("+----+--------------------------+----------------------+----------+-------+\n");
        printf("| %42s %30s\n", "data is empty", "|");
        printf("+----+--------------------------+----------------------+----------+-------+\n");
    }
    getch();
}

void addlist()
{
    char name[30], type[30];
    int qty, price;
    do
    {
        printf("\nInput Name of the new item [3..20] : ");
        scanf("%s", name);
    } while (strlen(name) >= 20 || strlen(name) <= 3);
    do
    {
        printf("Input type of the new item[processor/graphic card/memory] : ");
        scanf("%s", &type);
    } while (strcmp(type, "processor") != 0 && strcmp(type, "graphic card") != 0 && strcmp(type, "memory") != 0);
    do
    {
        printf("Input quantity of the new item [1..20] : ");
        scanf("%d", &qty);
    } while (qty <= 1 && qty >= 20);
    do
    {
        printf("Input price of the new item [$1..$1000] : ");
        scanf("%d", &price);
    } while (price <= 1 && price >= 1000);
    current = (struct Node *)malloc(sizeof(struct Node));
    strcpy(current->type, type);
    strcpy(current->name, name);
    current->qty = qty;
    current->price = price;
    current->next = current->prev = NULL;

    if (head == NULL)
    {
        head = tail = current;
    }
    else
    {
        head->prev = current;
        current->next = head;
        head = current;
    }
    printf("\n\n--- Add new Item Success ---\n");
    getch();
}

void selllist()
{
    if (head == NULL)
    {
        printf("\n There are no item available.");
    }
    else if (head == tail)
    {
        current = head;
        printf("\n the recently added item <%s - %s> is being delete\n", current->name, current->type);
        head = tail = NULL;
        free(current);
    }
    else
    {
        current = head;
        printf("\n the recently added item <%s - %s> is being delete\n", current->name, current->type);
        head = head->next;
        head->prev = NULL;
        free(current);
    }
    getch();
}

int getCount(struct Node *head)
{
    int count = 0;
    current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
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
            showlist();
            break;
        case 2:
            system("cls");
            addlist();
            break;
        case 3:
            system("cls");
            selllist();
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