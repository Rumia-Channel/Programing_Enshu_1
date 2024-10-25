#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srandom((unsigned)time(NULL));
	long int ranum;
	long int usrin;
	int min=1;
	int max=100;
	scanf("%ld", &usrin);
	ranum = (random() % (max - min) + min);
	//DEBUG
	//ranum = 21;
	printf("%ld \n", ranum);
	printf("%ld \n", usrin);
	if (usrin == ranum){
		printf("correct! \n");
	} else{
		printf("miss! \n");
	}
	return 0;
}
