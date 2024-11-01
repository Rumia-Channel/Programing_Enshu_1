#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int l_abs(long int lnumb){
	if (lnumb<-0){
	lnumb=lnumb*-1;
	}
	return lnumb;
}

int ndiff(long int usrin, long int answr){

	long int compa;

	printf("正解は%dで、", answr);

	//DEBUG
	//printf("%ld \n", num1);
	//printf("%ld \n", num2);

	compa = l_abs((usrin - answr));
	if (compa==0){
		printf("正解！ \n");
		return 1;
	} else if (compa<=5){
		printf("めっちゃ惜しい! \n");
	} else if (compa<=10){
		printf("惜しい！ \n");
	} else{
		printf("残念！ \n");
	}
	return 0;
}

int main(void)
{
	long int ranum;
	long int usrin;
	int min=1;
	int max=100;
	int retry=3;
	int nturn=0;
	int nmtry=0;

	while(retry>nturn){
		
		nturn++;
		nmtry=0;

		printf("ターン%dです。 \n", nturn);
		
		//予想処理
		while(1){
			nmtry++;
			srandom((unsigned)time(NULL));
			printf("第%d回目の予想> ", nmtry);
			scanf("%ld", &usrin);
			ranum = (random() % (max - min) + min);
			//DEBUG
			ranum = 21;

			if (ndiff(usrin, ranum)==1){
				printf("%d回目の予想で正解しました。\n", nmtry);
				break;
			}
		}

	}
	return 0;
}
