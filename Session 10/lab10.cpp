#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void printMenu()
{
    printf("\n Directed Graph Representation");
    printf("\n =============================\n");
    printf("\n 1. show Adjaceny Matrix ");
    printf("\n 2. show Degree of all vertices");
    printf("\n 3. Exit \n\n");
}

void graph(int matrix[50][50], int n)
{
    int i, j;
    char reply;
    printf("\n");
    fflush(stdin);
    for (i = 1; i <= n; i++)
    {
        fflush(stdin);
        for (j = 1; j <= n; j++)
        {
            fflush(stdin);
            if (i == j)
            {
                matrix[i][j] = 0;
                continue;
            }
            fflush(stdin);
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :", i, j);
            scanf("%c", &reply);
            fflush(stdin);
            if (reply == 'y' || reply == 'Y')
            {
                matrix[i][j] = 1;
            }
            else
                matrix[i][j] = 0;
        }
    }
    return;
}

void DegreeVertices()
{
    int matrix[50][50];
    int n;
    int in, out, i, j;

    do
    {
        fflush(stdin);
        printf("\n\n How Many vertices ? (max=10) : ");
        scanf("%d", &n);
        fflush(stdin);
    } while (n < 1 || n > 10);
    fflush(stdin);
    graph(matrix, n);
    printf("\n\n Vertex \t  In_degree \t  Out_degree \t  Total_degree\n");
    for (i = 1; i <= n; i++)
    {
        in = out = 0;

        for (j = 1; j <= n; j++)
        {
            if (matrix[j][i] == 1)
                in++;
        }
        for (j = 1; j <= n; j++)
            if (matrix[i][j] == 1)
                out++;
        printf("\n %5d\t\t\t%d\t\t%d\t\t%d\n", i, in, out, in + out);
    }
    return;
}

void MatrixAdjacecy()
{
    int matrix[50][50];
    int input, in, out, baris, kolom;

    do
    {
        fflush(stdin);
        printf("\n\n How Many Vertices ? (max=10) : ");
        scanf("%d", &input);
        fflush(stdin);
    } while (input < 1 || input > 10);
    fflush(stdin);
    graph(matrix, input);
    printf("\n\n\n Adjacency Matrix of this Grap");
    printf("\n_______________________________");
    printf("\n\n Vertex    ");
    for (baris = 1; baris <= input; baris++)
    {
        printf("%d\t  ", baris);
    }
    printf("\n\n");

    for (baris = 1; baris <= input; baris++)
    {
        printf("\n%5d	", baris);
        for (kolom = 1; kolom <= input; kolom++)
            printf("  %d	", matrix[baris][kolom]);
        printf("\n");
    }
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
        case (1):
        {
            MatrixAdjacecy();
            getch();
            system("cls");
            main();
            break;
        }
        case (2):
        {
            DegreeVertices();
            getch();
            system("cls");
            main();
            break;
        }
        case (3):
        {
            exit(0);
            break;
        }
        default:
            menu = 99;
        }
    }

    return 0;
}
