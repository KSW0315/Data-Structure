#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

struct penting
{
    char nama[40], course[41], test[10], nim[10];
    int score;
    struct penting *next;
    struct penting *prev;
} *front = NULL, *end = NULL, *data, *input;

int aku = 0;

void baris(int n)
{
    for (int a = 0; a < n; a++)
    {
        printf("-");
    }
}

void isi()
{

    data = (struct penting *)malloc(sizeof(struct penting));
    fflush(stdin);
    do
    {
        printf("Input Student name [5..30]: ");
        scanf("%[^\n]", data->nama);
        fflush(stdin);
    } while (strlen(data->nama) < 5 || strlen(data->nama) > 30);
    fflush(stdin);
    do
    {
        printf("Input NIM [10]:");
        scanf("%s", &data->nim);
        fflush(stdin);

    } while (strlen(data->nim) < 10);
    fflush(stdin);
    do
    {
        printf("Input Course [5..30] :");
        scanf("%[^\n]", data->course);
        fflush(stdin);
    } while (strlen(data->course) < 5 || strlen(data->course) > 30);
    fflush(stdin);

    do
    {
        printf("Input Test [Mid Test/Final Test] :");
        scanf("%[^\n]", data->test);
        fflush(stdin);
    } while (strcmp(data->test, "Mid Test") != 0 && strcmp(data->test, "Final Test") != 0);
    fflush(stdin);
    do
    {

        printf("Input Score [0..100]:");
        scanf("%d", &data->score);
        fflush(stdin);
    } while ((data->score) < 0 || (data->score) > 100);
}

void tambah()
{
    isi();
    if (front == NULL)
    {
        front = data;
        end = data;
        front->prev = NULL;
        front->next = NULL;
    }
    else
    {
        end->next = data;
        data->prev = end;
        end = data;
    }
    data->next = NULL;
    end->next = NULL;
    aku++;
    puts("--- Add New Score Success ---");
}

void menu1()
{
    if (front == NULL)
    {
        printf("\t\t\t---DATABASE STUDENT SCORE---\n\n");
        baris(97);
        printf("\n");
        printf("|No. |Stundent Name		| NIM		   | Course		   | Test 	| Score |\n");
        printf("\n");
        baris(97);
    }
    else
    {
        input = front;
        printf("\n\t\t\t---DATABASE STUDENT SCORE---\n\n");
        baris(97);
        printf("\n");
        printf("|No. |Stundent Name		| NIM		   | Course		   | Test 	| Score |\n");
        printf("\n");
        baris(97);

        for (int i = 0; i < aku; i++)
        {
            printf("\n| %d.  |", i + 1);
            printf("%-26s|", input->nama);
            printf(" %-17s|", input->nim);
            printf(" %-22s|", input->course);
            printf(" %-11s|", input->test);
            printf(" %6d|", input->score);

            input = input->next;
        }
        printf("\n");
        baris(97);
    }
}

int main()
{
    int pilih;
    printf("DATABASE STUDENT SCORE\n");
    printf("++++++++++++++++++++++++++++++\n\n");
    printf("1.View Student Score\n2.Add New Score\n3.Exit \n");

    printf("\n>>>Input Your Choise : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case (1):
    {
        system("cls");
        menu1();
        getch();
        system("cls");
        main();
        break;
    }
    case (2):
    {
        system("cls");
        tambah();
        getch();
        system("cls");
        main();
        break;
    }
    }
}