#include<stdio.h>

int main()
{
    char str[100];
    int l;
    printf("Enter the string\n");
    scanf("%s",str);
    l=stringlength(str);
    printf(" no of characters are%d\n",l);
    return 0;
}
int stringlength(char str[])
{
    int i=0;
    while(str[i])
    {
        i++;
    }
    return i;
}
