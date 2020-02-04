#include <stdio.h>

int WaitingTime(int p_id[], int size, int burst_t[], int arrival_t[], int wait_t[])
{
	int remain_t[size];

	for(int i=0; i<size; i++) {
		remain_t[i] = burst_t[i];
	}
	int complete = 0, t = 0, min = 9999;
	int shortest = 0, finish_t;
	int check = 0;

	while(complete != size) {
		
		for(int j=0; j<size; j++) {
			if((arrival_t[j] <= t) && (remain_t[j] < min) && remain_t[j] > 0) {
				min = remain_t[j];
				shortest = j;
				check = 1;
			}
		}

		if(check == 0) {
			t++;
			continue;
		}

		remain_t[shortest]--;

		min = remain_t[shortest];
		if(min == 0) {
			min = 9999;
		}

		if(remain_t[shortest] == 0) {
			complete++;
			check = 0;

			finish_t = t+1;
			
			wait_t[shortest] = finish_t-burst_t[shortest]-arrival_t[shortest];

			if(wait_t[shortest] < 0) {
				wait_t[shortest] = 0;
			}
		}
		t++;

	}

	return 0;
}

int TurnAroundTime(int p_id[], int size, int burst_t[], int arrival_t[], int wait_t[], int turn_at[]) 
{
	for(int i=0; i<size; i++) {
		turn_at[i] = burst_t[i] + wait_t[i];
	}
	return 0;
}

int AverageTime(int p_id[], int size, int burst_t[], int arrival_t[]) 
{
	int wait_t[size], turn_at[size], total_wait_t = 0, total_turn_at = 0;

	WaitingTime(p_id, size, burst_t, arrival_t, wait_t);
	TurnAroundTime(p_id, size, burst_t, arrival_t, wait_t, turn_at);
	
	printf("Processes  Burst Time  Arrival Time  Waiting Time  Turn around time\n");
	for(int i=0; i<size; i++) {
		total_wait_t = total_wait_t + wait_t[i];
		total_turn_at = total_turn_at + turn_at[i];
		printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d ",p_id[i], burst_t[i], arrival_t[i], wait_t[i], turn_at[i]);
	}

	printf("\nAverage Waiting Time = %f", (float)total_wait_t/(float)size);
	printf("\nAverage Turn Around Time = %f \n", (float)total_turn_at/(float)size);

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
