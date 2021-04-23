#include<stdio.h>
#include<conio.h>

int main()
{
	int i,j=0,x,temp,n,a[20];
	clrscr();
	printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");

	for(i=0;i<n;i++)
	{
		a[i]=(rand() % 100)+1;

	}


    printf("The original array is: \n");
    for (i=0;i<n;i++)
    {
	printf("\t%d",a[i]);
    }


    //Insertion Sort Logic
	for(i=0; i<n; i++)
	{
		temp = a[i];
		j = i-1;
		
		while(j>=0 && a[j]>temp) {
			a[j+1]=a[j];
			j--;
		}
		
		a[j+1] = temp;
		
		printf("\n");
		printf("\n");
		for(x=0; x<n; x++) {
			printf("\t%d",a[x]);	
		}		
	}
	
	printf("\n");
	printf("\n");
	
	printf("The sorted array is: \n");
    for (i = 0; i < n; i++)
    {
    	printf("\t%d", a[i]);
	}
	
	return 0;    
}