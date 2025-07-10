#include<stdio.h>
void bubblesort(int a[],int n)
{
	int i,j,temp;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		//for(j=0; j<n-1; j++)
			//Both loops for j are correct can use any one
		{
			if(a[j] > a[j + 1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}

}

void main()
{
	int N;
	int a[N],i;
	printf("Enter the number of terms:");
	scanf("%d",&N);
	printf("Enter terms:");
	for(i=0; i<N; i++)
	{
		scanf("%d",&a[i]);
	}
	bubblesort(a,N);
	printf("Final array:\n");
	for(i=0; i<N; i++)
	{
		printf("%d\t",a[i]);
	}
}
