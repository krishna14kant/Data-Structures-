#include<stdio.h>

int main()
{
int arr[5]={2,4,5,3,1};
int size=5;
int temp;
for(int i=0;i<size;i++)
{
	printf("%d",arr[i]);
}
printf("\n");
for(int i=0;i<size-1;i++)
{
	for(int j=0;j<size-i-1;j++)
	{
		if(arr[j]>arr[j+1])
			{
				temp=arr[j];
		        arr[j]=arr[j+1];
		        arr[j+1]=temp;
	        }

	}
}
for(int i=0;i<size;i++)
{
	printf("%d",arr[i]);
}
return 0;	
}