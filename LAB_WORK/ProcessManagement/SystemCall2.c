#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int a=5,return_value,return_value2;
	printf("Hello World\n");
	printf("THe process ID is %d\n",(int)getpid());
	printf("The parent process ID is %d\n", (int)getppid());
	return_value = system("ps");
	return_value2 = system("ps -e -o pid,ppid,command");

	return return_value;
}
