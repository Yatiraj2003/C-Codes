#include<stdio.h>
int main()
{
    char s1[100];
    char s2[100];
    printf("Enter the string 1 and string 2\n");
    scanf("%s %s",s1,s2);
    stringconcatenate(s1,s2);
    printf("concatenated string is = %s\n",s1);
    return 0;
}

stringconcatenate(char s1[],char s2[])
{
    int i=0,j=0;
    while(s1[i])
    {
        i++;
    }
    while(s2[j])
    {
        s1[i]=s2[j];
        i++;
        j++;
    }
    s1[i]='\0';
}
