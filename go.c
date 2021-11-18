#include<stdio.h>

int[][2] go()
{
    int m[2][2] = {1,2,3,4};
    return m;
}

int main()
{
    int m[2][2];

    m = go();

    for(int i = 0 ; i < 2 ; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf(" %d ",m[i][j]);
        }
        printf("\n");
    }
}
