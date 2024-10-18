#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srandom((unsigned)time(NULL));
	long int ranum;
	ranum = random();
	printf("%ld \n", ranum);
	return 0;
}
