#include<stdio.h>
int main()
{
    char src[100];
    char dest[100];
    printf("Enter the source\n");
    scanf("%s",src);
    printf("Enter the destination\n");
    scanf("%s",dest);
    stringcopy(dest,src);
    printf("%s\n",dest);
    return 0;
}

void stringcopy(char src[],char dest[])
{
    int i=0;
    while(src[i])
    {
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';
}
