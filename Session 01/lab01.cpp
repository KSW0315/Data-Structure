#include <stdio.h>
#include <Windows.h>
#include <string>

struct Kue
{
    char code[6];
    char name[21];
    int stock;
    int price;
};

int arr_qty_price[4][2] =
    {
        {10, 25000},
        {5, 20000},
        {12, 30000},
        {7, 17500}};

const char *arr_code_name[][2] =
    {
        {"CK001", "Blue Cake"},
        {"CK009", "Choco Cake"},
        {"CK017", "Lemon Cake"},
        {"CK023", "uWu Cake"}};

int inMenu;
struct Kue Products[100];
int prodIndex;
char inCode[6];
int inQuantity;
bool isInCodeOk;
bool isInQuaOk;
bool isStockOk;

void initCake()
{
    for (int i = 0; i < 4; i++)
    {
        strcpy(Products[i].code, arr_code_name[i][0]);
        strcpy(Products[i].name, arr_code_name[i][1]);
        Products[i].stock = arr_qty_price[i][0];
        Products[i].price = arr_qty_price[i][1];
    }
}

void showCake()
{
    printf("BLUE CAKE SHOP CASHIER\n");
    printf("======================\n\n");
    printf("No. | Cake Code | Cake Name | Available | Price\n");
    printf("--------------------------------------------------------------\n");
    for (int a = 0; a < 4; a++)
    {
        printf("0%d. | %5s | %-20s | %9d | Rp. %d \n", a + 1, Products[a].code, Products[a].name, Products[a].stock, Products[a].price);
    }
    printf("--------------------------------------------------------------\n");
}

void Menu()
{
    printf("\nMenu :\n");
    printf("1. Sell\n");
    printf("2. Add stock\n");
    printf("3. Exit\n");
    printf("Input Choice : ");
    scanf("%d", &inMenu);
    fflush(stdin);
}

void Sell()
{
    isStockOk = true;
    do
    {
        isInCodeOk = false;
        printf("\nInput Cake Code [5 Char] : ");
        scanf("%[^\n]", &inCode);
        fflush(stdin);
        for (int a = 0; a < 4; a++)
        {
            if (strcmp(Products[a].code, inCode) == 0)
            {
                isInCodeOk = true;
                prodIndex = a;
                if (Products[prodIndex].stock == 0)
                {
                    isStockOk = false;
                    printf("\n\n== Stock is empty ==");
                    getchar();
                }
            }
        }
        if (isInCodeOk == false)
        {
            printf("\n===The Cake Code doesn't exist===\n");
        }
    } while (isInCodeOk == false);
    if (isStockOk == true)
    {
        do
        {
            isInQuaOk = true;
            printf("Input Quantity [0..%d] : ", Products[prodIndex].stock);
            scanf("%d", &inQuantity);
            fflush(stdin);
            if (inQuantity < 0 || inQuantity > Products[prodIndex].stock)
            {
                isInQuaOk = false;
            }
        } while (isInQuaOk == false);

        printf("\n\nTotal price is : Rp %d,- x %d = Rp %d,-\n\n", Products[prodIndex].price, inQuantity, (inQuantity * Products[prodIndex].price));
        Products[prodIndex].stock -= inQuantity;
        printf("\n--- Thank You ---");
        getchar();
    }
}

void Stock()
{
    do
    {
        isInCodeOk = false;
        printf("\nInput Cake Code [5 Char] : ");
        scanf("%[^\n]", &inCode);
        fflush(stdin);
        for (int a = 0; a < 4; a++)
        {
            if (strcmp(Products[a].code, inCode) == 0)
            {
                isInCodeOk = true;
                prodIndex = a;
            }
        }
        if (isInCodeOk == false)
        {
            printf("\nThe Cake Code doesn't exist\n");
        }
    } while (isInCodeOk == false);
    do
    {
        isInQuaOk = true;
        printf("Input Quantity [0..10] : ", Products[prodIndex].stock);
        scanf("%d", &inQuantity);
        fflush(stdin);
        if (inQuantity < 0 || inQuantity > 10)
        {
            isInQuaOk = false;
        }
    } while (isInQuaOk == false);
    Products[prodIndex].stock += inQuantity;
    printf("\n--- Adding Stock Success ---");
    getchar();
}

int main()
{
    initCake();
    do
    {
        printf("\n");
        showCake();
        Menu();
        switch (inMenu)
        {
        case 1:
        {
            Sell();
            break;
        }
        case 2:
        {
            Stock();
            break;
        }
        }
    } while (inMenu != 3);
}