#include <stdio.h>
#include <stdlib.h>

void a(void)
{
	printf("you are in function a\n");
	exit(EXIT_SUCCESS);
}

void out(void)
{
	printf("atexit() succeeded!\n");
	exit(EXIT_SUCCESS);
}

int main()
{
	printf("hello1\n");
	if(atexit(out)) {
		fprintf(stderr,"atexit() failed!n");
	}
	printf("hello2\n");
	printf("hello3\n");
	a();
	printf("last call!!\n");
	return 0;
}
