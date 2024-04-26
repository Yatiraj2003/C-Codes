// Binary Search in C
#include <stdio.h>
void read(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
}

int binarySearch(int array[], int x,int n, int low, int high)
{
  while (low <= high)
    {
    int mid = (low+high) / 2;

    if (array[mid] == x)
      return mid;

    else if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main()
 {
  int array[100];
  int n,result,x;
  printf("Enter the size of array\n");
  scanf("%d",&n);
  printf("Enter the key element in the array\n");
  scanf("%d",&x);
  printf("Enter the array elements\n");
  read(array,n);

  result = binarySearch(array, x,n, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}
