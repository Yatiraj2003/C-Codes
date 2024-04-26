#include<stdio.h>
#include<stdlib.h>
#define I 32767
int edges[3][9]={{1,1,2,2,3,4,4,5,5},{2,6,3,7,4,5,7,6,7},{25,5,12,10,8,16,14,20,18}};
int s[8]={0,-1,-1,-1,-1,-1,-1,-1};
int included[9]={0};
int t[2][6];

void Union(int u,int v)
{
    if(s[u]<s[v])
    {
        s[u]=s[u]+s[v];
        s[v]=u;
    }
    else
    {
        s[v]=s[u]+s[v];
        s[u]=v;
    }
}

int find(int u)
{
    int x=u;
    while(s[x]>0)
    {
        x=s[x];
    }
    return x;
}

int main()
{
    int i=0,j,k,n=7,e=9,min,u,v;
    while(i<n-1)
    {
        min=I;
        for(j=0;j<e;j++)
        {
            if(included[j]==0 && edges[2][j]<min)
            {
                min=edges[2][j];
                k=j,u=edges[0][j];
                v=edges[1][j];
            }
        }
        if(find(u)!=find(v))
        {
            t[0][i]=u,t[1][i]=v;
            Union(find(u),find(v));
            i++;
        }
        included[k]=1;
    }
    for(i=0;i<n-1;i++)
  {
      printf("(%d,%d)\n",t[0][i],t[1][i]);
  }
    return 0;
}
