сортировки
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define K 5
 void Command()//комманды, в принципе не нужны
{
    printf("\n1 - New array \n");
    printf("2 - ChooseSort \n");
    printf("3 - InsertionSort \n");
    printf("4 - BubbleSort \n");
    printf("5 - CountingSort \n");
    printf("6 - Exit \n");
}
 void Gen(int a[], int n)//генерация массива из 5 значений
{
    int i;
    srand((unsigned int)time(0));
    for (i = 0; i < n; i++)
    {
        a[i] =((double) K) / RAND_MAX * rand();
    }
}
 void Print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
 void ChooseSort(int a[], int n)// сортировка выбором
{
    int i, j, tmp, ind;
    for (i = 0; i < n - 1; i++)
    {
        ind = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[ind] > a[j])
                ind = j;
        }
        tmp = a[ind];
        a[ind] = a[i];
        a[i] = tmp;
    }
}
 void InsertionSort(int a[], int n)//сортировка вставками
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > temp))
        {
            a[j + 1] = a[j];
            a[j] = temp;
            j--;
        }
    }
}
 void BubbleSort(int a[], int n)//пузырьком
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}
 void CountingSort(int a[], int n)//подсчетом
{
    int b[K];
    int i, j, idx = 0;
    for (i = 0; i < K; i++)
        b[i] = 0;
    for (i = 0; i < n; i++)
        b[a[i]]++;
    for (i = 0; i < K; i++)
    {
        for (j = 0; j < b[i]; j++)
            a[idx++] = i; 
    }
}
 void main()
{
    int a[N];
    int i;
    Gen(a, N);
    Print(a, N);
    do
    {
        Command();
        scanf("%d", &i);
        printf("\n");
        switch (i) {
        case 1:
            Gen(a, N);
            break;
        case 2:
            ChooseSort(a, N);
            break;
        case 3:
            InsertionSort(a, N);
            break;
        case 4:
            BubbleSort(a, N);
            break;
        case 5:
            CountingSort(a, N);
            break;
        }
        Print(a, N);
    } while (i != 6); 
} 
