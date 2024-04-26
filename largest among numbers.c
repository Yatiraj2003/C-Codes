#include <stdio.h>
int main() {
  int n,i,index,temp;
   int arr[100];
  printf("Enter the number of elements : ");
  scanf("%d", &n);

  for ( i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < n; i++) {
    if (arr[0] < arr[i]) {
      arr[0] = arr[i];
      index=i;
    }
  }

 int j=0,k=index;

 while(j<k)
 {
     temp=arr[j];
     arr[j]=arr[k];
     temp=arr[k];

 }
 for(i=0;i<n;i++)
 {
     printf("%d ",arr[i]);
 }


  return 0;
}
