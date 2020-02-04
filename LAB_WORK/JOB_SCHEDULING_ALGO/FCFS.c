#include <stdio.h>

int WaitTime(int p_id[], int size, int burst_t[], int wait_t[])
{
	wait_t[0]=0;
	
	for(int i=1; i<size; i++) {
		wait_t[i] = burst_t[i-1] + wait_t[i-1];
	}	

}

int TurnAroundTime(int p_id[], int size, int burst_t[], int wait_t[], int ta_t[])
{
	for(int i=0; i<size; i++) {
		ta_t[i] = burst_t[i] + wait_t[i];
	}
}

int AverageTime(int p_id[], int size, int burst_t[])
{
	int wait_t[size], ta_t[size], total_wt=0, total_tat=0;

	WaitTime(p_id, size, burst_t, wait_t);
	TurnAroundTime(p_id, size, burst_t, wait_t, ta_t);	
	
	printf("Process     Burst time     Waiting Time     Turn around time\n");
	for(int i=0; i<size; i++) {
		total_wt = total_wt + wait_t[i];
		total_tat = total_tat + ta_t[i];
		printf(" %d",(i+1));
		printf("              %d ", burst_t[i]);
		printf("              %d ", wait_t[i]);
		printf("              %d \n", ta_t[i]);
	}
	float avg_wt = (float)total_wt/(float)size;
	float avg_tat = (float)total_tat/(float)size;
	printf("Average waiting time = %f\n",avg_wt);
	printf("Average turn around time = %f\n",avg_tat);

}

int main()
{
	int p_id[100], size, burst_t[100];
	
	printf("Enter no. of process available: \n");
	scanf("%d", &size);

	printf("Enter process id with burst time: \n");
	for(int i=0; i<size; i++)
	{
		printf("P_ID: \n");
		scanf("%d", &p_id[i]);
		printf("Burst time: \n");
		scanf("%d", &burst_t[i]);
	}	

	AverageTime(p_id, size, burst_t);
	return 0;
}
