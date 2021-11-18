#include <stdio.h>

int main()
{
    char S[1000]="hii Welcome to VS Code";
    FILE *fp;
    fp=fopen("f2.txt","a");
    fputs(S,fp);
    fclose(fp);
    return 0;

    
}
