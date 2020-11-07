#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct makroni
{
    char size_makroni[30];
    int level_makroni;
    struct makroni *next, *prev;
} * head, *tail, *current;

void printMakroni()
{
    if (head != NULL)
    {
        current = head;
        while (current != NULL)
        {
            if (current->prev == NULL)
                printf("\n [ %-6s makroni : hot level %2d ] -> Top", current->size_makroni, current->level_makroni);
            else
                printf("\n [ %-6s makroni : hot level %2d ]", current->size_makroni, current->level_makroni);

            current = current->next;
        }
    }
    else
    {
        printf(" Makroni Stock <STACK>");
    }
    printf("\n\n");
};

void addMakroni(char text_makroni[], int level)
{
    current = (struct makroni *)malloc(sizeof(makroni));
    strcpy(current->size_makroni, text_makroni);
    current->level_makroni = level;
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
}

void sellMakroni()
{
    if (head == NULL)
    {
        printf("No Data");
    }
    else if (head == tail)
    {
        current = head;
        head = tail = NULL;
        free(current);
    }
    else
    {
        current = head;
        head = head->next;
        head->prev = NULL;
        free(current);
    }
}

void menu_level(char makroni_makroni[30])
{
    int anw;
    do
    {
        printf("\nInput Level [5...15]: ");
        scanf("%d", &anw);
        fflush(stdin);
    } while (anw <= 5 && anw >= 15);

    addMakroni(makroni_makroni, anw);
}

void menu_qty()
{
    char makroni_makroni[30];
    char anw[6];
    do
    {
        printf("\nInput Choice [small/medium/large]: ");
        scanf("%s", &anw);
        fflush(stdin);
    } while (strcmp(anw, "small") != 0 && strcmp(anw, "medium") != 0 && strcmp(anw, "large") != 0);

    if (strcmp(anw, "small") == 0)
    {
        menu_level("small");
    }
    else if (strcmp(anw, "medium") == 0)
    {
        menu_level("medium");
    }
    else if (strcmp(anw, "large") == 0)
    {
        menu_level("large");
    }
}

int getCount(struct makroni *head)
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
    int menu;
    printMakroni();
    do
    {
        do
        {
            system("cls");
            printf("ADE MAKRONI STOCK\n_________________\n\n");

            printMakroni();
            printf("Option:\n");
            printf("1. Stock of makroni\n");
            printf("2. Sell makroni\n");
            printf("3. Exit\n");
            printf("\n>> Input Choice : ");
            scanf("%d", &menu);
            fflush(stdin);
        } while (menu < 1 || menu > 3);
        switch (menu)
        {
        case 1:
            if (getCount(head) < 10)
                menu_qty();
            else
                printf("MAX");

            break;
        case 2:
            sellMakroni();

            break;
        }
    } while (menu != 3);
}