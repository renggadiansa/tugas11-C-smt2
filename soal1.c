#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int Data[MAX];
int SequentialSearch(int x, int *banding) {
    int i = 0;
    bool ketemu = false;
    while ((!ketemu) && (i < MAX)) {
        (*banding)++;
        if(Data[i] == x)
            ketemu = true;
        else
            i++;
    }
    if(ketemu)
        return i;
    else
        return -1;
}

void Tukar (int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int L, int R) {
    int i, j, x;
    x = Data[(L+R)/2];
    i = L;
    j = R;
    while (i <= j)
    {
        while(Data[i] < x)
            i++;
        while(Data[j] > x)
            j--;
        if(i <= j)
        {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }
    if(L < j)
        QuickSort(L, j);
    if(i < R)
        QuickSort(i, R);
}

int BinarySearch(int x, int *banding) {
    int L = 0, R = MAX-1, m;
    bool ketemu = false;
    while((L <= R) && (!ketemu)) {
        (*banding)++;
        m = (L + R) / 2;
        if(Data[m] == x)
            ketemu = true;
        else if (x < Data[m])
            R = m - 1;
        else
            L = m + 1;
    }
    if(ketemu)
        return m;
    else
        return -1;
}

void soal1() {
    int i;
    srand(0);
    printf("\nDATA : ");
    for (i = 0; i < MAX; i++) {
        Data[i] = rand()%100+1;
        printf("%d ", Data[i]);
    }

    int Kunci1, Kunci2;
    printf("\nKunci : ");
    scanf("%d", &Kunci1);
    int banding = 0;
    int ketemu1 = SequentialSearch(Kunci1, &banding);
    if(ketemu1>0)
        printf("Data ditemukan pada posisi %d dengan %d perbandingan (sequential search)\n", ketemu1, banding);
    else
        printf("Data tidak ditemukan\n");

    QuickSort(0, MAX-1);


    printf("\nKunci : ");
    scanf("%d", &Kunci2);
    int ketemu2 = BinarySearch(Kunci2, &banding);
    if(ketemu2>0)
        printf("Data ditemukan pada posisi %d dengan %d perbandingan (binary search)", ketemu2, banding);
    else
        printf("Data tidak ditemukan");
}