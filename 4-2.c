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
	long int compa;
	scanf("%ld", &usrin);
	ranum = (random() % (max - min) + min);
	//DEBUG
	//ranum = 21;
	printf("%ld \n", ranum);
	printf("%ld \n", usrin);
	compa = usrin - ranum;
	if (compa==0){
		printf("正解！ \n");
	} else if (compa<5 && compa>-5){
		printf("めっちゃ惜しい! \n");
	} else if (compa<10 && compa>-5){
		printf("惜しい！ \n");
	} else{
		printf("残念！ \n");
	}
	return 0;
}
