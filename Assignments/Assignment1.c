#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	int proc1, proc2, proc3;

	proc1 = fork();

	if(proc1 == 0) {
		sleep(3);
		printf("First process called!, PID= %d\n",getpid());
	}
	else {
		proc2 = fork();
		if(proc2 == 0) {
			sleep(2);
			printf("Second process called!, PID= %d\n", getpid());
		}
		else {
			proc3 = fork();
			if(proc3 == 0) {
				printf("Third process called!, PID= %d\n", getpid());
			}
			else {
				sleep(3);
				printf("Main process called!, PID= %d\n", getppid());
			}

		}
	}
	return 0;
}
