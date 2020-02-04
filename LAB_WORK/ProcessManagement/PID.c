#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int a = 5;
	printf("Hello World\n");
	printf("THe process ID is %d\n", (int)getpid());
	printf("The parent process ID is %d\n", (int)getppid());

	return 0;
}
