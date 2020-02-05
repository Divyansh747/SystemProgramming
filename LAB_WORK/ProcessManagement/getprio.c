#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main()
{
	int ret;

	ret = getpriority(PRIO_PROCESS, 0);
	printf("nice value is %d\n", ret);

	return 0;
}
