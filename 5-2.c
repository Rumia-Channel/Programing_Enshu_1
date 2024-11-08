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

/*整数以外が入力された際の無限ループを回避したかったが、動作せず
long int ch_ns(char *input){
	char *end;
	printf(input);
	long int rtnum = strtol(input, &end, 10);
	if (*end != '\0'){
		return 0;
	}
	return rtnum;
}
*/

int main(void)
{
	long int ranum;
	/*TEST用 動作せず
	 * char *input;*/
	long int usrin;
	int min=1;
	int max=100;
	int retry=3;
	int nturn=0;
	int hwtry=0;
	double avtry;

	while(retry>nturn){
		
		nturn++;

		printf("ターン%dです。 \n", nturn);
		
		//試行回数を初期化
		int nmtry=0;
		//予想処理
		while(1){
			nmtry++;
			srandom((unsigned)time(NULL));
			printf("第%d回目の予想> ", nmtry);
			scanf("%ld", &usrin);
			
			/*TEST用 動作しないため保留 なぜか数値だろうが文字だろうがメモリダンプする。
			 * scanf("%c", &input);
			printf("TEST1");
			usrin = ch_ns(input);
			if (usrin==0){
				printf("不正な文字列が入力されました。1～100までの10進数の数値のみを入力してください。\n");
				nmtry--;
				continue;
			}*/
			ranum = (random() % (max - min) + min);
			
			//DEBUG
			ranum = 21;

			if (ndiff(usrin, ranum)==1){
				printf("%d回目の予想で正解しました。\n", nmtry);
				break;
			}
		}

	avtry = (double)hwtry/(double)nturn;
	printf("%dターンで%d回の予想をしました。スコア(平均回数)は%f回です。\n", nturn,hwtry,avtry);

	}
	return 0;
}
