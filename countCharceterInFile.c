#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen("hello.c", "r");

    char ch;
    int count = 0;

    ch = fgetc(fp);

    while (!feof(fp))
    {
        if (ch != 32 && ch != 13)
            count++;
        ch = fgetc(fp);
    }
    printf("%d" , count);
    fclose(fp);
    return 0;
}
