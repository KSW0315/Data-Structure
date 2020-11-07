#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node
{
    int carPrice, carCode;
    struct node *left, *right;
} * tree;

int keyCode = 0;
int newCode;
int status;
char empty_message[37] = "--- There's no Car in the tree ---";
char not_found_message[37] = "---Car Code is Not Found---";
char failed_message[99] = "\n\n---Add New Car Failure---\nErr: Car Code Already Exist";
char success_message_update[37] = "\n\n---Update Car Price Success---";
char success_message_add[37] = "\n\n---Add New Car Success---";

void printMenu()
{
    printf("LA OTTO CAR\n");
    printf("*************\n\n");
    printf("1. Add New Car\n");
    printf("2. Update Car Price\n");
    printf("3. Inorder, Postorder, Preorder\n");
    printf("4. Exit\n\n");
}

void checkCode(struct node *tree)
{
    if (tree != NULL)
    {

        if (tree->carCode != newCode)
        {
            if (tree->carCode > newCode)
            {

                if (tree->left != NULL)
                {
                    checkCode(tree->left);
                }
                else
                {
                    status = 1;
                }
            }

            if (tree->carCode < newCode)
            {
                if (tree->right != NULL)
                {
                    checkCode(tree->right);
                }
                else
                {
                    status = 1;
                }
            }
        }
        else if (tree->carCode == newCode)
        {
            printf(failed_message);
            status = 0;
        }
    }
    else
    {
        status = 1;
    }
}

struct node *addCar()
{
    struct node *newnode, *nodeptr, *parentptr;
    int price;

    do
    {
        printf("Input Car Code X[1-9][0-9][0-9] : X");
        fflush(stdin);
        scanf("%d", &newCode);
    } while (newCode < 100 || newCode > 999);

    checkCode(tree);

    if (status != 0)
    {
        do
        {
            printf("Input Car Price $[4000..99999] : $");
            scanf("%d", &price);
        } while (price < 4000 || price > 99999);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->carCode = newCode;
        newnode->carPrice = price;
        newnode->left = NULL;
        newnode->right = NULL;

        if (tree == NULL)
        {
            tree = newnode;
            tree->left = NULL;
            tree->right = NULL;
        }
        else
        {
            parentptr = NULL;
            nodeptr = tree;

            while (nodeptr != NULL)
            {
                parentptr = nodeptr;
                if (newCode <= tree->carCode)
                {
                    nodeptr = nodeptr->left;
                }
                else
                {
                    nodeptr = nodeptr->right;
                }
            }

            if (newCode <= tree->carCode)
            {
                parentptr->left = newnode;
            }
            else
            {
                parentptr->right = newnode;
            }
        }

        printf(success_message_add);
        return tree;
    }
}

void updateCar(struct node *tree)
{
    int newPrice;

    if (tree->carCode != keyCode)
    {
        if (tree->carCode > keyCode)
        {

            if (tree->left != NULL)
            {
                updateCar(tree->left);
            }
            else
            {
                printf(not_found_message);
            }
        }

        if (tree->carCode < keyCode)
        {
            if (tree->right != NULL)
            {
                updateCar(tree->right);
            }
            else
            {
                printf(not_found_message);
            }
        }
    }
    else if (tree->carCode == keyCode)
    {
        int hasil;
        printf("\nCar Code	: X%d", tree->carCode);
        printf("\nCar Price	: $%d\n", tree->carPrice);
        do
        {
            printf("\nInput Car Price $[4000..99999] : $");
            scanf("%d", &newPrice);
        } while (newPrice < 4000 || newPrice > 99999);

        printf(success_message_update);
        tree->carPrice = newPrice;
    }
}

void preOrder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("-X%d [ $ %-6d]\n", ptr->carCode, ptr->carPrice);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void inOrder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inOrder(ptr->left);
        printf("-X%d [ $ %-6d]\n", ptr->carCode, ptr->carPrice);
        inOrder(ptr->right);
    }
}

void postOrder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("-X%d [ $ %-6d]\n", ptr->carCode, ptr->carPrice);
    }
}

void sortby()
{
    if (tree != NULL)
    {

        printf("Preorder : \n");
        preOrder(tree);
        printf("\nInorder : \n");
        inOrder(tree);
        printf("\nPostorder : \n");
        postOrder(tree);
        return;
    }

    printf(empty_message);
    return;
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
            addCar();
            getch();
            break;
        case 2:
            system("cls");
            do
            {
                printf("Input Car Code X[1-9][0-9][0-9] : X");
                fflush(stdin);
                scanf("%d", &keyCode);
            } while (keyCode < 100 || keyCode > 999);
            updateCar(tree);
            getch();
            break;
        case 3:
            system("cls");
            sortby();
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