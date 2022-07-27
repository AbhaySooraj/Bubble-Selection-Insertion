/*To implement Bubble sort*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0,struct timeval t1)
{
	return(t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void display(int n,int arr[])
{	
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \t",arr[i]);
	}
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int x,n,i,j=0,temp,choice,minpos,key;
	
	printf("\n Enter number of elements :");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
	}
	
	printf("\n The unsorted elements are : \n");
	display(n,arr);
	
	printf(" \n\n\n MENU \n\n 1. Bubble Sort \n 2. Selection Sort \n 3. Insertion Sort \n\n Enter your choice :");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
		{
			gettimeofday(&t0, NULL);
			for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-i-1;j++)
				{
					if(arr[j]>arr[j+1])
					{
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
					}
				}
			}
			printf("\n The sorted elements are :");
			display(n,arr);
			gettimeofday(&t1, NULL);
			elapsed=timedifference_msec(t0,t1);
			printf("\n Bubble Sort executed in %f milliseconds.\n", elapsed);
			break;
		}
		
		case 2:
		{
			gettimeofday(&t0, NULL);
			for(i=0;i<n-1;i++)
			{
				minpos=i;
				for(j=i+1;j<n;j++)
				{
					if(arr[j]<arr[minpos])
					{
					minpos=j;
					}
				}
				temp=arr[minpos];
				arr[minpos]=arr[i];
				arr[i]=temp;
			}
			printf("\n The sorted elements are :");
			display(n,arr);
			gettimeofday(&t1, NULL);
			elapsed=timedifference_msec(t0,t1);
			printf("\n Selection Sort executed in %f milliseconds.\n", elapsed);
			break;
		}
		
		case 3:
		{
			gettimeofday(&t0, NULL);
			for(i=1;i<n;i++)
			{
				key=arr[i];
				j=i-1;
				while(j>=0 && arr[j]>key)
				{
					arr[j+1]=arr[j];
					j=j-1;
				}
				arr[j+1]=key;
			}
			printf("\n The sorted elements are :");
			display(n,arr);
			gettimeofday(&t1, NULL);
			elapsed=timedifference_msec(t0,t1);
			printf("\n Insertion Sort executed in %f milliseconds.\n", elapsed);
			break;
		}
	
		default:
		{
			printf("\n WRONG OPTION !!! \n");
			break;
		}
	}
}
		
