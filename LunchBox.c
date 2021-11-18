#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct
{
    int top;
    int capacity;
    int *p;
} Heap;

Heap *createHeap(int n)
{
    Heap *h;
    h = (Heap *)malloc(sizeof(Heap));
    if (h == NULL)
    {
        printf("\nMemory is not Allocated");
        return NULL;
    }
    h->capacity = n;
    h->top = -1;
    h->p = (int *)malloc(sizeof(int) * n);
    if (h->p == NULL)
    {
        printf("\nMemory is not Allocated");
        return NULL;
    }

    return h;
}
Heap *insert(Heap *h, int v)
{
    int i, j, temp;

    h->top = h->top + 1;
    i = h->top;
    h->p[i] = v;

    for (j = i; j > 0; j = (j - 1) / 2)
        if (h->p[(j - 1) / 2] < v)
        {
            temp = h->p[j];
            h->p[j] = h->p[(j - 1) / 2];
            h->p[(j - 1) / 2] = temp;
        }
    return h;
}
// void display(Heap *a)
// {
//     int i;
//     for ( i = 0; i <= a->top; i++)
//     {
//         printf(" %d ", a->p[i]);
//     }

// void buildHeap(Heap *h, int a[], int n)
// {
//     if (h == NULL)

//         return;
//     int i;
//     for (i = 0; i < n; i++)

//         h->p[i] = a[i];
//     for (i = (n - 1) / 2; i >= 0; i--)

//         heapifiy(h, i);
// }

int rightChild(Heap *h, int i)
{
    if (2 * i + 2 > h->top)
        return -1;
    return (2 * i + 2);
}

int leftChild(Heap *h, int i)
{
    if (2 * i + 1 > h->top)
        return -1;
    return (2 * i + 1);
}

void heapifiy(Heap *h, int i)
{
    int r, l, max, temp;
    l = leftChild(h, i);
    r = rightChild(h, i);
    if (l != -1 && h->p[l] > h->p[i])
        max = l;
    else
        max = i;
    if (r != -1 && h->p[r] > h->p[max])
        max = r;
    if (max != i)
    {
        temp = h->p[i];
        h->p[i] = h->p[max];
        h->p[max] = temp;
        heapifiy(h, max);
    }
}

int *HeapSort(int *a, int n)
{
    Heap *h;
    h = createHeap(n);
    int old_size, temp, i;

    // int i;
    for (i = 0; i < n; i++)
        h = insert(h, a[i]);
    //  display(h);
    old_size = n;

    for (i = n - 1; i > 0; i--)
    {
        temp = h->p[h->top];
        h->p[h->top] = h->p[0];
        h->p[0] = temp;
        h->top--;
        heapifiy(h, 0);
    }
    h->top = old_size - 1;
    return h->p;
}

int main()
{
    int t, N, M, i , j;
    scanf("%d", &t);
    int count[t];
    for (i = 1; i <= t; i++)
    {
        count[i] = 0;
        scanf("%d %d",&N,&M);
        int *a = (int *)malloc(sizeof(int) * M);

        for (j = 0; j < M; j++)
        {
            scanf("%d", &a[j]);
        }

        a = HeapSort(a, M);

        for (j = 0; j < M; j++)
        {
            if (a[j] <= N)
            {
                N = N - a[j];
                count[i]++;
            }
            else
                break;
        }
        free(a);
    }

    for ( i = 1; i <=t; i++)
    {
        printf("%d",count[i]);
        printf("\n");
    }

    return 0;
}
