#include <stdio.h>
int main()
{
    char a[10];
    int i,n,key;
    char item[20];
    printf("\nEnter number of elements of an array:\n");
    scanf("%d",&n);
    printf("\nEnter elements: \n");
    for (i=0; i<n; i++)
	scanf("%s", &a[i]);
    printf("\nEnter item to search: ");
    scanf("%s", &item);
    for (i=0; i<=9; i++)
    {
	key=(strcmp(a[i],item));
       if(key==1)
	{
	    printf("\nItem found at location %d", i+1);
	    break;
	}
	else
	{
		printf("\nitem Not found in array");
	}

       }

}