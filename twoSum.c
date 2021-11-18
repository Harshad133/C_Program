
// leet code problem number 1 two sum

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

int *HeapSort(int a[], int n)
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

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{

    int *sort , *two;
    sort = HeapSort(nums, numsSize);
    int i, j, temp, end, m, p;

    for (i = 0; i < numsSize; i++)
    {
        if (sort[i] > target)
            break;
    }
    end = i - 1;

    two = (int *)malloc(sizeof(int) * 2);
    for (i = 0; i <= end; i++)
    {
        temp = target - sort[i];

        for (j = i + 1; j <= end; j++)
        {
            if (temp == sort[j])
            {
                for (m = 0; m < numsSize; m++)
                    if (nums[m] == sort[i])
                        break;
                two[0] = m;

                for (p = 0; p < numsSize; p++)
                    if (nums[p] == sort[j] && p != m)
                        break;
                two[1] = p;

                return two;
            }
            if (temp < sort[j])
            {
                break;
            }
        }
    }
    // return 1;
}

int main()
{
    int n, target, *p, *r;
    printf("enter size = ");
    scanf("%d", &n);

    p = (int *)malloc(sizeof(int) * n);
    printf("\nenter target = ");
    scanf("%d", &target);

    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    r = twoSum(p, n, target, r);

    printf("\n[ %d , %d ]", r[0], r[1]);
    return 0;
}
