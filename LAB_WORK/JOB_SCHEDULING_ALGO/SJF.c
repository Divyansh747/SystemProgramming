#include <stdio.h>

AverageTime(int p_id[], int size, int burst_t[], int arrival_t[])
{
	int min,k=1,btime=0,temp,i,j,sum=0,total_arrival=0,turn_time[size],wait_t[size];
	float wavg=0,tavg=0,tsum=0,wsum=0;

	for(i=0;i<size;i++) 
	{
		for(j=0;j<size;j++)
		{
			if(arrival_t[i]<arrival_t[j])
			{
				temp=p_id[j];
				p_id[j]=p_id[i];
				p_id[i]=temp;

				temp=arrival_t[j];
				arrival_t[j]=arrival_t[i];
				arrival_t[i]=temp;

				temp=burst_t[j];
				burst_t[j]=burst_t[i];
				burst_t[i]=temp;
			}	
		}
	}

	for(j=0;j<size;j++)
	{
		btime=btime+burst_t[j];
		min=burst_t[k];
		for(i=k;i<size;i++)
		{
			if(btime>=arrival_t[i] && burst_t[i]<min)
			{
				temp=p_id[k];
				p_id[k]=p_id[i];
				p_id[i]=temp;

				temp=arrival_t[k];
				arrival_t[k]=arrival_t[i];
				arrival_t[i]=temp;

				temp=burst_t[k];
				burst_t[k]=burst_t[i];
				burst_t[i]=temp;
			}	
		}

		k++;
	}

	wait_t[0]=0;
	for(i=1;i<size;i++)
	{
		sum=sum+burst_t[i-1];
		wait_t[i]=sum-arrival_t[i];
		wsum=wsum+wait_t[i];
	}

	wavg=wsum/size;
	for(i=0;i<size;i++)
	{
		total_arrival=total_arrival+burst_t[i];
		turn_time[i]=total_arrival-arrival_t[i];
		tsum=tsum+turn_time[i];

	}
	tavg=tsum/size;

	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(i=0;i<size;i++)
	{
		printf("\n p%d\t %d\t %d\t\t %d\t\t\t\%d",p_id[i],burst_t[i],arrival_t[i],wait_t[i],turn_time[i]);
	}
	printf("\n\nAverage waiting time: %f",wavg);
	printf("\nAverage turn around time: %f\n",tavg);
	return 0;
}


int main()
{
	int p_id[100], size, burst_t[100], arrival_t[100];
	
	printf("Enter no. of process available: \n");
	scanf("%d", &size);

	printf("Enter process id with burst time & arrival time: \n");
	for(int i=0;i<size;i++)
	{
		printf("P_ID: \n");
		scanf("%d", &p_id[i]);
		printf("Burst time: \n");
		scanf("%d", &burst_t[i]);
		printf("Arrival time: \n");
		scanf("%d", &arrival_t[i]);
	}	

	AverageTime(p_id, size, burst_t, arrival_t);
	return 0;
}
